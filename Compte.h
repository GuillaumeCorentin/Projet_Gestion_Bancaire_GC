#ifndef COMPTE_H
#define COMPTE_H

#include <iostream>
#include <string>
using namespace std;

class Compte {
private:
      
    float Solde_Compte;
    string NumeroCompte;
    string Type_Compte;
    string RIB;
    int chequier;

public:

    int solde_Compte;
    string num_Compte;
    string quel_compte;
    string rib_compte;
    int cheque;

    Compte(); // Constructeur par défaut
    Compte(float, string, string, string, int); // Constructeur par défaut
    void afficher(); // Méthode pour afficher les informations du compte
    string recup_num_Compte();
    int recup_solde();
    string recup_type_Compte();
    string recup_RIB();

    void Crediiter(float);
    void Debiter(float);

    int recup_chequier();
    void commdander_chequier();
    



};

#endif