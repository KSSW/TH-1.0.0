#ifndef FILECONVERTER_H
#define FILECONVERTER_H

#ifdef FILECONVERTER_EXPORTS
#define FILECONVERTER_API __declspec(dllexport)
#else
#define FILECONVERTER_API __declspec(dllimport)
#endif

#include <stdio.h>

extern "C" {
    FILECONVERTER_API int next_ac3(unsigned char* buf, FILE* ac3_fd, FILE* out_fd);
    FILECONVERTER_API int next_truehd(unsigned char* buf, FILE* truehd_fd, FILE* out_fd);
    FILECONVERTER_API int process_files(const char* truehd_path, const char* ac3_path, const char* out_path, int truncate);
}

#endif // FILECONVERTER_H