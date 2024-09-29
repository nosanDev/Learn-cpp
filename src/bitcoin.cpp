#include <iostream>
#include <bitcoin.h>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

bool game = true;
int Money_EUR = 1500;
int Money_BTC = 0;

void court_Bitcoin() {
    float valeur_B = 25000.0f;
    int i = 0;

    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(-3000.0f, 3000.0f); 

    while (game) {
        float variation = distribution(generator);
        valeur_B += variation; 

        std::cout << "Valeur actuelle du bitcoin "<< ": " << valeur_B << " EUR" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(2)); 
    }
}

void acheter(int money_btc, int money, int valeur_bitcoin) {

    std::cout << "\n\n\nVeuillez entrer la somme en euro que vous allez dépenser et nous vous indiquerons la somme en bitcoin à laquelle cela correspond." << std::endl;
    int somme;
    cin >> somme;
    int somme_en_bitcoin = money / valeur_bitcoin;  
    std::cout << "\n\n\nLa somme de votre argent en bitcoin est de " << somme_en_bitcoin << "  BTC. \n Acceptez vous de faire la transaction : o = oui, n = non." << std::endl;
    bool reponse;
    cin >> reponse;
    if (reponse) {
        money_btc += somme_en_bitcoin;
    }else {
        std::cout << "La transaction à été annulé après votre décision choisis." << std::endl;
    }

    
}

void vendre() {
}

void bitcoin() {

    bool game = true;

    cout << R"(                         

    Bienvenue dans le jeu de gestion d'argent (bitcoin), voici les principes de ce jeu :
     - Tout d'abord vous commencez avec une somme de 1500€ et l'objectif est d'atteindre
     la plus grosse somme d'argent en moins de 2 semaines soit 14 jours.
     - Le jeu se déroule sous format épistolaire, )" << endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));


    // ------------------ Cycle de jours ------------------

    cout << "\nVotre monnaie à bien été initialisée à " << Money_EUR << " €" << endl;

    for (int jours = 1; jours <= 14; jours++){
        std::cout << "\nNous sommes le " << jours << " du mois de janvier." << std::endl;

        // Jour restant

        if (jours > 0){
            std::cout << "\nIl vous reste " << 14 - jours << " jours pour gagner le plus d'argent possible" << std::endl;
        }else {
            std::cout << "\nC'est terminé, il ne vous reste plus de jours pour gagner de l'argent." << std::endl;
            bool game = false;
        }

        std::this_thread::sleep_for(std::chrono::seconds(5));

        // Action que le joueur réalise durant la journée

        int times = 0;

        for (int i = 0; i >= 31; i++) {
            times++;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        // definir le court du bitcoin

        int valeur_court_BTC = 0;
        

        while (times <= 100) {
            int action;
            bool QuitterJour = false;
            bool Quitter = false;
                
            std::cout << R"(Veuillez entrez un nombre correspondant à l'action que vous souhaitez executer :
            - 1 : Pour acheter une quantité de bitcoin
            - 2 : Pour vendre une quantité de bitcoin
            - 3 : Passer
            - 4 : Pour revenir au menu principal du programme (quitter le jeu)))" << std::endl;
            cin >> action;



            switch (action) {
                case 1:
                    acheter(Money_EUR, );
                    break;
                case 2:
                    vendre();
                    break;
                case 3:
                    break;
                case 4:
                    game = false;
                    break;
                default:
                    cout << "Choix invalide, veuillez réessayer." << endl;

            }

            // court du bitcoin

            while (game) {
                court_Bitcoin();

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

    // resultat

    int sommeBTCandEUR = 0;
    Money_EUR += sommeBTCandEUR;

    std::cout << "\n\n\n\nBravo, ton score est de " << Money_EUR << " €, après avoir ajouté ton portefeuille de bitcoin, c'est énorme, tu as bien joué.";

}
