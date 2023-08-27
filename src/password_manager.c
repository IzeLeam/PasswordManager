#include <stdio.h>
#include <stdlib.h>
#include <openssl/aes.h>

#include "../include/file_manager.h"
#include "../include/utils.h"
#include "../include/password_manager.h"

const char* PASSWORDS_PATH = "../passwords";

void encrypt(const unsigned char *input, unsigned char *output, const unsigned char *key) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    AES_encrypt(input, output, &aes_key);
}

void decrypt(const unsigned char *input, unsigned char *output, const unsigned char *key) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 128, &aes_key);
    AES_decrypt(input, output, &aes_key);
}

void add_password(const char* password) {

    char* filename;

    char hash[1000];
    encrypt(password, hash, "coucou");

    printf("Please enter the filename : ");
    filename = ask_for_string();

    create_file(PASSWORDS_PATH, filename);
    write_to_file(PASSWORDS_PATH, filename, hash);
}