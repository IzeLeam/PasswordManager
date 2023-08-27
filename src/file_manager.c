#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

char* fullpath_of(const char* path, const char* element) {
    size_t path_len = strlen(path);
    size_t element_len = strlen(element);
    char* fullpath = (char*)malloc(path_len + element_len + 2);
    
    if (fullpath) {
        snprintf(fullpath, path_len + element_len + 2, "%s/%s", path, element);
    }
    
    return fullpath;
}

void create_file(const char* path, const char *filename) {

    char* fullPath = fullpath_of(path, filename);

    FILE *file = fopen(fullPath, "w");
    fclose(file);
    free(fullPath);
}

void write_to_file(const char* path, const char *filename, const char *data) {

    char* fullPath = fullpath_of(path, filename);

    FILE *file = fopen(fullPath, "w");
    fprintf(file, "%s", data);
    fclose(file);
    free(fullPath);
}

char* read_file(const char* path, const char *filename) {

    char* fullPath = fullpath_of(path, filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *content = (char *)malloc(file_size + 1);
    if (content == NULL) {
        printf("Erreur lors de l'allocation de mémoire.\n");
        fclose(file);
        return NULL;
    }

    size_t read_size = fread(content, 1, file_size, file);
    if (read_size != file_size) {
        printf("Erreur lors de la lecture du fichier.\n");
        fclose(file);
        free(content);
        return NULL;
    }

    content[file_size] = '\0';
    fclose(file);

    return content;
}

void create_directory(const char* path, const char *dirname) {

    char* fullPath = fullpath_of(path, dirname);

    mkdir(fullPath);
    free(fullPath);
}

int file_exists(const char* path, const char *filename) {

    char* fullPath = fullpath_of(path, filename);

    FILE *file = fopen(fullPath, "r");
    if (file) {
        fclose(file);
        free(fullPath);
        return 1;
    }
    free(fullPath);
    return 0;
}

int directory_exists(const char *path, const char* dirname) {
    char* fullPath = fullpath_of(path, dirname);

    DWORD fileAttributes = GetFileAttributes(fullPath);
    free(fullPath);

    if (fileAttributes != INVALID_FILE_ATTRIBUTES && (fileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
        return 1;
    } else {
        return 0;
    }
}


