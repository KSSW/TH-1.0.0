#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

// 获取比特流
class GetBitStreams {
public:
    GetBitStreams(int argc, char* argv[]) {
        parseArguments(argc, argv);
        checkFileExtensions();
        readAC3();
        readMLP();
    }

    std::string fileNameAC3;
    std::string fileNameTHD;
    std::string outputFileName;
    std::vector<uint8_t> bitStreamAC3;
    std::vector<uint8_t> bitStreamMLP;

private:
    void parseArguments(int argc, char* argv[]) {
        if (argc < 3) {
            throw std::invalid_argument("Usage: program <AC3 file> <THD file> [-o output file]");
        }
        fileNameAC3 = argv[1];
        fileNameTHD = argv[2];
        if (argc > 3 && std::string(argv[3]) == "-o" && argc > 4) {
            outputFileName = argv[4];
        }
        else {
            outputFileName = "output.thd+ac3";
        }
    }

    void checkFileExtensions() {
        if (fileNameAC3.substr(fileNameAC3.find_last_of(".") + 1) != "ac3") {
            throw std::invalid_argument("Error: The AC3 file doesn't have a .ac3 extension.");
        }
        if (fileNameTHD.substr(fileNameTHD.find_last_of(".") + 1) != "thd") {
            throw std::invalid_argument("Error: The MLP file doesn't have a .thd extension.");
        }
    }

    void readAC3() {
        std::ifstream stream(fileNameAC3, std::ios::binary);
        if (!stream) {
            throw std::runtime_error("Error: Cannot open the AC3 file.");
        }
        bitStreamAC3.assign((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
        stream.close();

        if (bitStreamAC3.size() < 2 || bitStreamAC3[0] != 0x0B || bitStreamAC3[1] != 0x77) {
            throw std::invalid_argument("Error: The .ac3 file doesn't start with the AC3 sync word.");
        }
    }

    void readMLP() {
        std::ifstream stream(fileNameTHD, std::ios::binary);
        if (!stream) {
            throw std::runtime_error("Error: Cannot open the THD file.");
        }
        bitStreamMLP.assign((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
        stream.close();

        if (bitStreamMLP.size() < 8 || bitStreamMLP[4] != 0xF8 || bitStreamMLP[5] != 0x72 || bitStreamMLP[6] != 0x6F || bitStreamMLP[7] != 0xBA) {
            throw std::invalid_argument("Error: The .thd file doesn't have the major format sync.");
        }
    }
};

// 分割杜比数字帧
class SplitDolbyDigitalFrames {
public:
    SplitDolbyDigitalFrames(const std::vector<uint8_t>& bitStreamAC3) {
        checkSamplingFrequency(bitStreamAC3);
        getFrameSize(bitStreamAC3);
        splitFrames(bitStreamAC3);
    }

    std::vector<std::vector<uint8_t>> frameList;

private:
    uint8_t codeByte;
    size_t frameSize;

    void checkSamplingFrequency(const std::vector<uint8_t>& bitStreamAC3) {
        codeByte = bitStreamAC3[4];
        if (codeByte & 0xC0) {
            throw std::invalid_argument("Error: The AC3 bit stream has an unsupported sampling frequency.");
        }
    }

    void getFrameSize(const std::vector<uint8_t>& bitStreamAC3) {
        static const int words[] = { 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384, 448, 512, 640, 768, 896, 1024, 1152, 1280 };
        int frameSizeCode = (codeByte & 0x3F) >> 1;
        frameSize = words[frameSizeCode] * 2;
    }

    void splitFrames(const std::vector<uint8_t>& bitStreamAC3) {
        if (bitStreamAC3.size() % frameSize != 0) {
            throw std::invalid_argument("Error: There's a problem with the AC3 frames.");
        }
        size_t numberOfFrames = bitStreamAC3.size() / frameSize;
        frameList.resize(numberOfFrames);
        for (size_t i = 0; i < numberOfFrames; ++i) {
            frameList[i].assign(bitStreamAC3.begin() + i * frameSize, bitStreamAC3.begin() + (i + 1) * frameSize);
        }
    }
};

// 分割访问标头
class SplitAccessHeaders {
public:
    SplitAccessHeaders(const std::vector<uint8_t>& bitStreamMLP) {
        splitAccessHeaderLoop(bitStreamMLP);
        formatAccessHeaders();
        if (accessHeaderList.size() % 192 != 0) {
            formatLeftOverAccessHeaders();
        }
    }

    std::vector<std::vector<uint8_t>> formattedAccessHeaders;

private:
    std::vector<std::vector<uint8_t>> accessHeaderList;
    size_t startByte = 0;

    void getAccessUnitLength(const std::vector<uint8_t>& bitStreamMLP, size_t& accessUnitLength) {
        std::vector<uint8_t> accessUnitWordLength = { static_cast<uint8_t>(bitStreamMLP[startByte] & 0x0F), bitStreamMLP[startByte + 1] };
        accessUnitLength = (accessUnitWordLength[0] << 8 | accessUnitWordLength[1]) * 2;
    }

    void splitAccessHeaderLoop(const std::vector<uint8_t>& bitStreamMLP) {
        while (startByte < bitStreamMLP.size()) {
            size_t accessUnitLength;
            getAccessUnitLength(bitStreamMLP, accessUnitLength);
            accessHeaderList.emplace_back(bitStreamMLP.begin() + startByte, bitStreamMLP.begin() + startByte + accessUnitLength);
            startByte += accessUnitLength;
        }
    }

    void formatAccessHeaders() {
        size_t numberOfSegments = accessHeaderList.size() / 192;
        for (size_t i = 0; i < numberOfSegments * 192; i += 192) {
            formattedAccessHeaders.push_back(joinSegments(i, 0, 39));
            formattedAccessHeaders.push_back(joinSegments(i, 39, 77));
            formattedAccessHeaders.push_back(joinSegments(i, 77, 116));
            formattedAccessHeaders.push_back(joinSegments(i, 116, 154));
            formattedAccessHeaders.push_back(joinSegments(i, 154, 192));
        }
    }

    std::vector<uint8_t> joinSegments(size_t startIndex, size_t begin, size_t end) {
        std::vector<uint8_t> result;
        for (size_t i = begin; i < end; ++i) {
            result.insert(result.end(), accessHeaderList[startIndex + i].begin(), accessHeaderList[startIndex + i].end());
        }
        return result;
    }

    std::vector<uint8_t> joinSegmentsLeftover(const std::vector<std::vector<uint8_t>>& temp, size_t begin, size_t end) {
        std::vector<uint8_t> result;
        for (size_t i = begin; i < end; ++i) {
            result.insert(result.end(), temp[i].begin(), temp[i].end());
        }
        return result;
    }

    void formatLeftOverAccessHeaders() {
        size_t fullLength = accessHeaderList.size();
        size_t startIndex = (fullLength / 192) * 192;
        auto temp = std::vector<std::vector<uint8_t>>(accessHeaderList.begin() + startIndex, accessHeaderList.end());
        size_t tempLength = temp.size();
        if (tempLength <= 39) {
            formattedAccessHeaders.push_back(joinSegmentsLeftover(temp, 0, tempLength));
        }
        else if (tempLength <= 77) {
            formattedAccessHeaders.push_back(joinSegmentsLeftover(temp, 0, 39));
            formattedAccessHeaders.push_back(joinSegmentsLeftover(temp, 39, tempLength));
        }
        else if (tempLength <= 116) {
            formattedAccessHeaders.push_back(joinSegmentsLeftover(temp, 0, 39));
            formattedAccessHeaders.push_back(joinSegmentsLeftover(temp, 39, 77));
            formattedAccessHeaders.push_back(joinSegmentsLeftover(temp, 77, tempLength));
        }
        else if (tempLength <= 154) {
            formattedAccessHeaders.push_back(joinSegmentsLeftover(temp, 0, 39));
            formattedAccessHeaders.push_back(joinSegmentsLeftover(temp, 39, 77));
            formattedAccessHeaders.push_back(joinSegmentsLeftover(temp, 77, 116));
            formattedAccessHeaders.push_back(joinSegmentsLeftover(temp, 116, tempLength));
        }
        else {
            formattedAccess
