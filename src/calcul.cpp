#include <iostream>
#include "calcul.h"

using namespace std;

void calcul() {
    int a, b;
    char operateur;
    cout << "Entrez une opération (ex : 5 + 2): ";
    cin >> a >> operateur >> b;

    switch (operateur) {
        case '+': cout << a << " + " << b << " = " << a + b << endl; break;
        case '-': cout << a << " - " << b << " = " << a - b << endl; break;
        case '*': cout << a << " * " << b << " = " << a * b << endl; break;
        case '/': 
            if (b != 0)
                cout << a << " / " << b << " = " << a / b << endl;
            else
                cout << "Erreur : division par zéro.\n";
            break;
        default: cout << "Opérateur invalide.\n"; break;
    }
}
