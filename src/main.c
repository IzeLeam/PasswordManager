#include <stdlib.h>
#include <stdio.h>

#include "../include/password_gen.h"


int main(int argc, char** argv) {

    printf("\nLaunching Hash application...\n");
    printf(" _ _ _   _ \n");
    printf("|_ _  | | |\n");
    printf(" _ _| |_| |\n");
    printf("|  _   _ _|\n");
    printf("| | | |_ _ \n");
    printf("|_| |_ _ _|\n");

    printf("\nInitializing criterias...\n");
    init_password_gen();
    printf("Criterias initialized\n");

    printf("\nApplication Hash launched\n");

    char* password = generatePassword(WEAK);
    
    printf("Mot de passe généré : %s\n", password);
    
    free(password);
    return 0;
}