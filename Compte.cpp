#include "Compte.h"



Compte::Compte(float Lesolde, string Lenum_Compte, string Letype_Compte, string Lerib, int Lechequier)
{
    Solde_Compte = Lesolde;
    NumeroCompte = Lenum_Compte;
    Type_Compte = Letype_Compte;
    RIB = Lerib;
    chequier = Lechequier;
}

void Compte::afficher()
{
    cout << "Solde du compte : " << Solde_Compte << endl;
    cout << "Numéro de compte : " << NumeroCompte << endl;
    cout << "Type de compte : " << Type_Compte << endl;
}

string Compte::recup_num_Compte()
{
    num_Compte = NumeroCompte;
    return num_Compte;
}

int Compte::recup_solde()
{
    solde_Compte = Solde_Compte;
    return solde_Compte;
}

string Compte::recup_type_Compte()
{
    Type_Compte = Type_Compte;
    return Type_Compte;
}

string Compte::recup_RIB()
{
    rib_compte = RIB;
    return rib_compte;
}

void Compte::Crediiter(float montant)
{
    Solde_Compte += montant;
}

void Compte::Debiter(float montant)
{
    if (Solde_Compte >= montant)
    {
        Solde_Compte -= montant;
    }
    else
    {
        cout << "Solde insuffisant" << endl;
    }
}

int Compte::recup_chequier()
{
    cheque = chequier;
    return cheque;
}
void Compte::commdander_chequier()
{
    chequier = 1;
}



