#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/password_gen.h"

void init_password_gen() {

    const password_structure WEAK = {8, 0, 0, 0};
    const password_structure MEDIUM = {12, 2, 2, 0};
    const password_structure STRONG = {22, 6, 4, 0};
    const password_structure ROBUST = {44, 16, 10, 4};
    const password_structure SECURE = {76, 28, 16, 8};
}

char* generatePassword(const password_structure criteria) {

    srand(time(NULL));

    static const char charset_alpha_min[] = "abcdefghijklmnopqrstuvwxyz";
    static const char charset_alpha_maj[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static const char charset_decimal[] = "0123456789";
    static const char charset_special[] = "!@#$%^&*()-_+=[]{}|;:,.<>?";

    int total_length = criteria.alpha_min + criteria.alpha_maj + criteria.decimal + criteria.special;
    char* password = (char*)malloc(total_length + 1);

    if (password) {
        int index = 0;
        
        for (int i = 0; i < criteria.alpha_min; i++) {
            password[index++] = charset_alpha_min[rand() % (sizeof(charset_alpha_min) - 1)];
        }
        
        for (int i = 0; i < criteria.alpha_maj; i++) {
            password[index++] = charset_alpha_maj[rand() % (sizeof(charset_alpha_maj) - 1)];
        }
        
        for (int i = 0; i < criteria.decimal; i++) {
            password[index++] = charset_decimal[rand() % (sizeof(charset_decimal) - 1)];
        }
        
        for (int i = 0; i < criteria.special; i++) {
            password[index++] = charset_special[rand() % (sizeof(charset_special) - 1)];
        }
        
        password[index] = '\0';

        // Shuffle the password characters
        for (int i = total_length - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            char temp = password[i];
            password[i] = password[j];
            password[j] = temp;
        }
    }

    return password;
}