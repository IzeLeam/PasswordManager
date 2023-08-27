#include <stdlib.h>
#include <stdio.h>

#include "../include/password_gen.h"
#include "../include/menus.h"

int main(int argc, char** argv) {

    printf("\nLaunching Hash application...\n");
    printf(" _ _ _   _ \n");
    printf("|_ _  | | |\n");
    printf(" _ _| |_| |\n");
    printf("|  _   _ _|\n");
    printf("| | | |_ _ \n");
    printf("|_| |_ _ _|\n");
    printf("\nApplication Hash launched\n");

    print_main_menu();


    char* password = generatePassword(WEAK);
    
    printf("Mot de passe genere : %s\n", password);
    
    free(password);
    return 0;
}