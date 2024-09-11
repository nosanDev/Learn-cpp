#include <iostream>
#include "calcul.h"
#include "hangman.h"

using namespace std;

void afficherMenu() {
    cout << "Bienvenue sur ma console où vous pouvez trouver tous les petits programmes réalisés \npour que je puisses prendre de l'expérience.";
    cout << "\n\n\n===== Menu Principal =====" << endl;
    cout << "\n1. Calcul" << endl;
    cout << "\n2. Jeu du pendu" << endl;
    cout << "\n3. Quitter" << endl;
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
                quitter = true;
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
        }
    }

    return 0;
}
