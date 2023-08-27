#include <stdio.h>
#include <stdlib.h>

#include "../include/menu.h"

void print_menu(char* name, const char *list[], int menu_size) {

    printf("\nMenu %s :\n", name);
    for (int i = 0; i < menu_size; i++) {
        printf("%d. %s\n", i + 1, list[i]);
    }
    printf("0. Quitter\n");
}
