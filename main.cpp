#include <iostream>
#include "calcul.h"
#include "hangman.h"
#include "bitcoin.h"

using namespace std;

void afficherMenu() {
    cout << R"(
    
                                                                
            ,--.                                               
        ,--.'|                                               
    ,--,:  : |                                               
    ,`--.'`|  ' :   ,---.                                ,---,  
    |   :  :  | |  '   ,'\   .--.--.                 ,-+-. /  | 
    :   |   \ | : /   /   | /  /    '    ,--.--.    ,--.'|'   | 
    |   : '  '; |.   ; ,. :|  :  /`./   /       \  |   |  ,"' | 
    '   ' ;.    ;'   | |: :|  :  ;_    .--.  .-. | |   | /  | | 
    |   | | \   |'   | .; : \  \    `.  \__\/: . . |   | |  | | 
    '   : |  ; .'|   :    |  `----.   \ ," .--.; | |   | |  |/  
    |   | '`--'   \   \  /  /  /`--'  //  /  ,.  | |   | |--'   
    '   : |        `----'  '--'.     /;  :   .'   \|   |/       
    ;   |.'                  `--'---' |  ,     .-./'---'        
    '---'                              `--`---'                 v0.1

                    -- Branche des programmes d'apprentissage --    
    
    
    Bienvenue sur ma console où vous pouvez trouver tous les petits programmes réalisés \npour que je puisses prendre de l'expérience.)" << endl;
    cout << "\n\n\n===== Menu Principal =====" << endl;
    cout << "\n1. Calcul" << endl;
    cout << "\n2. Jeu du pendu" << endl;
    cout << "\n3. Jeu de Gestion d'argent (Bitcoin)" << endl;
    cout << "\n4. Quitter" << endl;
}

int main() {
    int choix;
    bool quitter = false;

    while (!quitter) {
        afficherMenu();
        cout << "Choisissez une option : ";
        cin >> choix;

        switch (choix) {
            case 1:
                calcul();
                break;
            case 2:
                hangman();
                break;
            case 3:
                bitcoin();
                break;
            case 4:
                quitter = true;
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
        }
    }

    return 0;
}
