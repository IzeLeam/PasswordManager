#include <stdlib.h>
#include <stdio.h>

#include "../include/password_gen.h"
#include "../include/file_manager.h"
#include "../include/menu.h"
#include "../include/main_menu.h"

const char* VERSION = "1.0";

int main(int argc, char** argv) {

    printf("\nLaunching Hash %s application... \n", VERSION);
    printf("      _   _   _ _ _   _ _ _   _   _\n");
    printf("    / / / / /  _  / /  _ _/ / / / /\n");
    printf("   / /_/ / / /_/ / / /_ _  / /_/ / \n");
    printf("  /  _  / /  _  / /_ _  / /  _  /  \n");
    printf(" / / / / / / / /  _ _/ / / / / /   \n");
    printf("/_/ /_/ /_/ /_/ /_ _ _/ /_/ /_/    \n");
    printf("\nApplication Hash %s launched     \n", VERSION);

    if (!directory_exists("..", "passwords")) {
        printf("create");
        create_directory("..", "passwords");
    }
    printf("OK");

    return 0;

    int quit = 0;
    int mod = MAIN;

    while (!quit) {
        switch(mod) {
            case 0 :
                quit = 1;
                break;
            case MAIN :
                mod = print_main_menu();
            case PASSWORD_GEN :
                mod = print_password_gen_menu();
            default :
                break;
        }
    }
    return 0;
}