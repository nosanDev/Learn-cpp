#include <iostream>
#include <bitcoin.h>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

void court_Bitcoin() {
    float valeur_B = 0;


}

void acheter() {
}

void vendre() {
}

void bitcoin() {
    cout << R"(Bienvenue dans le jeu de gestion d'argent (bitcoin), voici les principes de ce jeu :
     - Tout d'abord vous commencez avec une somme de 1500€ et l'objectif est d'atteindre
     la plus grosse somme d'argent en moins de 2 semaines soit 14 jours.
     - Le jeu se déroule sous format épistolaire, )" << endl;


    // Cycle de jours

    int Money_P = 1500;

    cout << "\nVotre money à bien été initialisé à " << Money_P << " €" << endl;

    for (int jours = 1; jours <= 14; jours++){
        std::cout << "\nNous sommes le " << jours << " du mois de janvier." << std::endl;

        // Jour restant

        if (jours > 0){
            std::cout << "\nIl vous reste " << 14 - jours << " jours pour gagner le plus d'argent possible" << std::endl;
        }else {
            std::cout << "\nC'est terminé, il ne vous reste plus de jours pour gagner de l'argent." << std::endl;
        }

        // Action que le joueur réalise durant la journée

        int times = 0;

        for (int i = 0; i >= 101; i++) {
            times++;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        

        while (times <= 100) {
            int action;
            bool QuitterJour = false;
            bool Quitter = false;
        
            std::cout << R"(Veuillez entrez un nombre correspondant à l'action que vous souhaitez executer :
            - 1 : Pour acheter une quantité de bitcoin
            - 2 : Pour vendre une quantité de bitcoin
            - 3 : Pour terminer la journée
            - 4 : Pour revenir au menu principal du programme (quitter le jeu))" << std::endl;
            cin >> action;

            switch (action) {
                case 1:
                    acheter();
                    break;
                case 2:
                    vendre();
                    break;
                case 3:
                    vendre();
                    break;
                case 4:
                    vendre();
                    break;
                default:
                    cout << "Choix invalide, veuillez réessayer." << endl;

            }
        }
        
    }

}
