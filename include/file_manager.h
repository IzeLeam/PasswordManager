#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

void create_file(const char* path, const char *filename);

void write_to_file(const char* path, const char *filename, const char *data);

char* read_file(const char* path, const char *filename);

void create_directory(const char* path, const char *dirname);

int file_exists(const char* path, const char *fileName);

int directory_exists(const char *path, const char* dirname);

#endif