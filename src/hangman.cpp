// Script bien commenté parce que j'apprends le cpp, donc pas envie d'oublier les bases...

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include<set>
#include<cctype>
#include<cstdlib>

using namespace std;

void display_word(const string& word, const set<char>& letter_found)
{
    // const string& word => le mot à afficher utiliser comme une référence constante, évite les copies inutiles
    // const set<char>& letter_found => lettre déjà trouvés également en constante pour la même cause

    string word_display; // initialisation d'une chaine de caractère pour afficher le mot avec et sans les lettres trouvées

    /* 
        letters_found.find(letter) : Cherche la lettre actuelle dans l'ensemble des lettres trouvées (letters_found).

        letters_found.end() : Si la lettre n'est pas trouvée dans l'ensemble, la fonction find retourne un itérateur égal à end().

        word_display += letter : Si la lettre a été trouvée (présente dans letters_found), elle est ajoutée à word_display.

        word_display += '_' : Si la lettre n'a pas été trouvée, un underscore _ est ajouté à word_display 
        pour indiquer que la lettre est encore inconnue.
    */

    for (char letter : word) { // parcour chaque lettre de mot
        if (letter_found.find(letter) != letter_found.end()) {
            word_display += letter;
        } else {
            word_display += '_';
        }
        word_display += ' '; // ajoute un espace à chaque fin de boucle entre les lettres
    }

    cout << word_display << endl;
}

void hangman() {

    // Mot aléatoire choisit parmis la liste

    std::vector<std::string> wordList = {"chat", "chien", "oiseau", "poisson", "souris", "éléphant", "girafe", "lion", "tigre", "ours",
            "pomme", "banane", "orange", "fraise", "raisin", "ananas", "kiwi", "mangue", "abricot", "pêche",
            "voiture", "vélo", "moto", "bus", "camion", "train", "avion", "bateau", "hélicoptère", "fusée",
            "football", "basketball", "tennis", "golf", "rugby", "volleyball", "natation", "athlétisme", "boxe", "karaté",
            "école", "université", "classe", "professeur", "étudiant", "cours", "livre", "stylo", "tableau", "ordinateur",
            "musique", "danse", "théâtre", "cinéma", "peinture", "sculpture", "photographie", "poésie", "roman", "thème",
            "hiver", "printemps", "été", "automne", "soleil", "lune", "étoile", "nuage", "pluie", "vent",
            "montagne", "plage", "forêt", "rivière", "lac", "cascade", "désert", "volcan", "île", "continent",
            "pizza", "hamburger", "spaghetti", "sushi", "salade", "sandwich", "yaourt", "glace", "gâteau", "chocolat",
            "famille", "amitié", "amour", "bonheur", "tristesse", "colère", "peur", "espoir", "rêve", "avenir"};

    srand(static_cast<unsigned int>(time(0)));

    int randomIndex= rand() % wordList.size();
    
    std::string randomWord = wordList[randomIndex];

    // Annonce du mot à commenter lorsque le developpement du petit jeu sera finit

    // std::cout << "Le mot généré est : " << randomWord << std::endl;

    // Annonce des règles

    std::string rules = R"(Si vous ne connaissez pas les règles du jeu du pendu : \n
    tout simplement essayé de  trouver le mot lettre par lettre en vous \n
    trompant au maximum 8 fois)";
     

    std::cout << rules << std::endl;

    // Le jeu en lui même ...

    std::set<char> letters_found;
    int luck = 8;
    char guess;

    while (luck > 0)
    {
        display_word(randomWord, letters_found);

        cout << "Devinez une lettre : ";
        cin >> guess; // affiche la lettre rentré
        guess = tolower(guess); // convertit en minuscule

        if (!isalpha(guess)) { // vérifie si le contenu est bien une lettre
            cout  << "Veuillez entrez une lettre parmis les 26 de l'alphabet" << endl;
            continue; // reprends le file de la boucle
        }

        if (letters_found.find(guess) != letters_found.end()) { // vérifie si une lettre guess à déjà été trouvée dans letter_found
            cout << "Vous avez déjà deviné cette lettre." << endl;
            continue;
        }

        if (randomWord.find(guess) != string::npos) { // vérifie si la lettre est dans le mot
            letters_found.insert(guess);
        } else {
            luck--; // décrémentation si je ne me trompes pas... inverse de luck++
            cout << "Lettre incorrecte. Il vous reste " << luck << " chances" << endl;
        }

        bool all_found = true;
        for (char letter : randomWord) {
            if (letters_found.find(letter) == letters_found.end()) {
                all_found = false;
                break;
            }
        }

        if (all_found) {
            cout << "Vous avez trouvé toutes les lettres du mot. Bravo. Le mot est bien " << randomWord << " ." << endl;
            return;
        }
    }

    cout << "Dommage, vous n'avez pas trouvé toutes les lettres du mot. Le mot était " << randomWord << " ." << endl;
}