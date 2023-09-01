#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/file_manager.h"
#include "../include/password_manager.h"
#include "../include/utils.h"

char* key;

void register_login() {

    char* tmp1 = malloc(sizeof(char) * 50);
    char* tmp2 = malloc(sizeof(char) * 50);

    while (1) {

        printf("Please enter a password to register : ");
        ask_for_string(tmp1);
        printf("Password again : ");
        ask_for_string(tmp2);

        if (strcmp(tmp1, tmp2) == 0) {
            break;
        } else {
            send_error_message("Differents passwords");
        }

    }

    strcpy(key, tmp1);


    char* secret = malloc(sizeof(char) * 50);
    printf("Enter a secret word : ");
    ask_for_string(secret);

    add_password(secret, "master");
    free(secret);
    free(tmp1);
    free(tmp2);
}

void usual_login() {

    char* tmp = malloc(sizeof(char) * 50);
    printf("Login with password : ");
    ask_for_string(tmp);
    strcpy(key, tmp);

    char* hash = read_file(PASSWORDS_PATH, "master");
    
    char* secret = malloc(sizeof(char) * 50);
    decrypt(hash, secret, key);
    printf("\nSecret word : %s\n", secret);
    free(secret);
    free(tmp);
}

void login() {

    key = malloc(sizeof(char) * 50);

    if (!file_exists(PASSWORDS_PATH, "master") || strcmp(read_file(PASSWORDS_PATH, "master"), "") != 0) {
        register_login();
        return;
    }
    usual_login();
}