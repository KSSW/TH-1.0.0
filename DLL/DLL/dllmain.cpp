#include "pch.h"
#include "FileConverter.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

HRESULT APIENTRY DllRegisterServer()
{
    // Add code to register the COM server
    return S_OK;
}

HRESULT APIENTRY DllUnregisterServer()
{
    // Add code to unregister the COM server
    return S_OK;
}

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllexport) void ProcessFiles(const char* thdFilePath, const char* ac3FilePath, const char* saveFilePath, int flag)
{
        process_files(thdFilePath, ac3FilePath, saveFilePath, flag);
}

FILECONVERTER_API int next_ac3(unsigned char* buf, FILE* ac3_fd, FILE* out_fd)
{
    int fsize;

    if (feof(ac3_fd))
        return -1;
    if (fread(buf, 1, 8, ac3_fd) != 8)
        return -1;
    switch (buf[4] & 0b00111110)
    {
    case 0b001000:
        fsize = 2 * 128;
        break;
    case 0b001010:
        fsize = 2 * 160;
        break;
    case 0b001100:
        fsize = 2 * 192;
        break;
    case 0b001110:
        fsize = 2 * 224;
        break;
    case 0b010000:
        fsize = 2 * 256;
        break;
    case 0b010010:
        fsize = 2 * 320;
        break;
    case 0b010100:
        fsize = 2 * 384;
        break;
    case 0b010110:
        fsize = 2 * 448;
        break;
    case 0b011000:
        fsize = 2 * 512;
        break;
    case 0b011010:
        fsize = 2 * 640;
        break;
    case 0b011100:
        fsize = 2 * 768;
        break;
    case 0b011110:
        fsize = 2 * 896;
        break;
    case 0b100000:
        fsize = 2 * 1024;
        break;
    case 0b100010:
        fsize = 2 * 1152;
        break;
    case 0b100100:
        fsize = 2 * 1280;
        break;
    default:
        return -1;
    }
    if (_fseeki64(ac3_fd, -8, SEEK_CUR) == -1L)
        return -1;
    if (fread(buf, 1, fsize, ac3_fd) != fsize)
        return -1;
    if (fwrite(buf, 1, fsize, out_fd) != fsize)
    {
        exit(1);
    }
    return 0;
}

FILECONVERTER_API int next_truehd(unsigned char* buf, FILE* truehd_fd, FILE* out_fd)
{
    int length;

    if (feof(truehd_fd))
        return -1;
    if (fread(buf, 1, 8, truehd_fd) != 8)
        return -1;
    length = buf[4] << 8 | buf[5];
    if (fread(buf, 1, length, truehd_fd) != length)
        return -1;
    if (fwrite(buf, 1, length, out_fd) != length)
    {
        exit(1);
    }
    return 0;
}

FILECONVERTER_API int process_files(const char* truehd_path, const char* ac3_path, const char* out_path, int truncate)
{
    unsigned char* buf;
    double truehd_time, ac3_time;
    FILE* truehd_fd, * ac3_fd, * out_fd;
    int ac3_eof, truehd_eof;

    buf = (unsigned char*)malloc(1024 * 1024);
    if (buf == NULL)
    {
        return 1;
    }

    errno_t err;
    err = fopen_s(&truehd_fd, truehd_path, "rb");
    if (err != 0 || truehd_fd == NULL)
    {
        return 0;
    }
    err = fopen_s(&ac3_fd, ac3_path, "rb");
    if (err != 0 || ac3_fd == NULL)
    {
        fclose(truehd_fd);
        return 0;
    }
    _unlink(out_path);
    err = fopen_s(&out_fd, out_path, "wb");
    if (err != 0 || out_fd == NULL)
    {
        fclose(truehd_fd);
        fclose(ac3_fd);
        return 0;
    }

    ac3_time = truehd_time = 0;
    ac3_eof = truehd_eof = 0;
    while (1)
    {
        if (ac3_eof && truehd_eof)
            break;
        if (!ac3_eof && (truehd_eof || ac3_time <= truehd_time))
        {
            if (next_ac3(buf, ac3_fd, out_fd) == -1)
            {
                ac3_eof = 1;
                if (truncate)
                    break;
            }
            else
                ac3_time += 0.032f;
        }
        else
        {
            if (next_truehd(buf, truehd_fd, out_fd) == -1)
            {
                truehd_eof = 1;
                if (truncate)
                    break;
            }
            else
                truehd_time += 1.0f / 1200;
        }
    }

    free(buf);
    fclose(truehd_fd);
    fclose(ac3_fd);
    fclose(out_fd);
    return 0;
}

#ifdef __cplusplus
}
#endif
