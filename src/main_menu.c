#include <stdio.h>
#include <stdlib.h>

#include "../include/menu.h"
#include "../include/utils.h"

int print_main_menu() {
    const char* list[] = {
        "Generer un mot de passe", "Liste des mots de passe", "Rechercher un mot de passe"
    };
    const int menu_size = sizeof(list);
    print_menu("main", list, menu_size);

    int mod = -1;
    while (mod < 0 || mod > menu_size) {
        mod = ask_for_integer();
        if (mod < 0 || mod > menu_size) {
            send_error_message("Valeur incorrecte");
        }
    }
    
    return mod;
}

