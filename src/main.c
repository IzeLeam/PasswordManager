#include <stdlib.h>
#include <stdio.h>

#include "../include/password_gen.h"
#include "../include/file_manager.h"
#include "../include/menu.h"

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

    if (!directory_exists("./", "passwords")) {
        printf("Creating passwords directory\n");
        create_directory("./", "passwords");
    }

    login();

    int quit = 0;
    int mod;

    while (!quit) {
        print_menu("Main", main_menu, size(main_menu));
        mod = select_in_menu(size(main_menu));
    }


    return 0;
}