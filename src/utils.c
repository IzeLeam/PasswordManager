#include <stdio.h>
#include <stdlib.h>

int ask_for_integer() {
    int num;
    printf("\nSaisissez un nombre : ");
    scanf("%d", &num);
    return num;
}

char ask_for_char() {
    char c; 
    printf("\nSaisissez un caractere : ");
    scanf("%c", &c);
    return c;
}

char* ask_for_string() {
    char* str;
    printf("\nSaisissez une chaine de caracteres : ");
    scanf("%s", &str);
    return str;
}

void send_error_message(char* message) {
    printf("\n/!\\ %s /!\\\n", message);
}