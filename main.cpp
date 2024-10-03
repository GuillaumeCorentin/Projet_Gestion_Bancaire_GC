#include <iostream>
#include <string>
#include "Client.h"
#include "Compte.h"
using namespace std;

string NumeroCompte;
string CodeSecure;

int selection; // Variable pour stocker la sélection de l'utilisateur
float montant;
int choix;
string reponse;
int boucle = 0;
int main()
{
    
    Compte CompteGuillaume1(1000, "0001", "Compte courant", "FR1234567891", 0); //Solde + NumeroCompte + Type_Compte + RIB
    Compte CompteSungur1(2000, "0002", "Compte courant", "FR1234567892", 0);
    Compte ComptePereira1(3000, "0003", "Compte courant", "FR1234567893", 0);

    Client Guillaume("Guillaume", "Corentin", "0787316820", "FR-AAAC9171G211", "0001", "2909"); //Nom + prénom + numéro de téléphone + numéro de CIN  + code de sécurité + RIB
    Client Sungur("Sungur", "Etem", "0678485214", "FR-AAAC9171G212", "0002", "0902");
    Client Pereira("Pereira", "Luka", "0745854125", "FR-AAAC9171G213", "0003", "1402");

while (true) {
    cout << " ==================== BIENVENUE DANS VOTRE BANQUE ==================== " << endl;
    cout << " ============================= SELECTION ============================= " << endl;
    cout << " 1. Me connecter " << endl;
    cout << " 2. Quitter " << endl;
    cout << " ============================ VOTRE CHOIX ============================ " << endl;
    cout << "Selection : ";
    cin >> selection;

    switch (selection) {
    case 1:

        cout << " ===================== CONNECTEZ-VOUS ===================== " << endl;
        cout << "Numéro de compte : ";
        cin >> NumeroCompte;
        cout << "Code de sécurité : ";
        cin >> CodeSecure;

        if (NumeroCompte == Guillaume.recup_num_Client() && CodeSecure == Guillaume.recup_code_Securite()) 
        {
            while(boucle != 1)
        {
            cout << "\nBienvenue " << Guillaume.recup_nom() << " " << Guillaume.recup_prenom() << " !" << endl << endl;
            switch (Guillaume.menu_client())
            {
            case 1:

                    Guillaume.afficher();
                    break;
            
            case 2:

                cout << "Le solde de votre compte est de " << CompteGuillaume1.recup_solde() << " euros" << endl;
                break;

            case 3:

                cout << "Entrez le montant à déposer : ";
                cin >> montant;
                CompteGuillaume1.Crediiter(montant);
                cout << "'Vous avez déposé " << montant << " euros" << endl;
                cout << "Votre nouveau solde est de " << CompteGuillaume1.recup_solde() << " euros" << endl;
                break;
            
            case 4:

                cout << "Entrez le montant à retirer : ";
                cin >> montant;
                CompteGuillaume1.Debiter(montant);
                cout << " Vous avez retiré " << montant << " euros" << endl;
                cout << "Votre nouveau solde est de " << CompteGuillaume1.recup_solde() << " euros" << endl;
                break;

            case 5:

                cout << "Quel est le montant à transférer ? ";
                cin >> montant;
                CompteGuillaume1.Debiter(montant);
                cout << " A qui voulez-vous transférer ? ";
                cin >> NumeroCompte;
                if(NumeroCompte == CompteGuillaume1.recup_num_Compte())
                {
                    cout << "Vous ne pouvez pas transférer de l'argent sur votre propre compte" << endl;
                }
                if (NumeroCompte == CompteSungur1.recup_num_Compte())
                {
                    CompteSungur1.Crediiter(montant);
                    cout << "Vous avez transféré " << montant << " euros à " << Sungur.recup_nom() << " " << Sungur.recup_prenom() << endl;
                }
                if (NumeroCompte == ComptePereira1.recup_num_Compte())
                {
                    ComptePereira1.Crediiter(montant);
                    cout << "Vous avez transféré " << montant << " euros à " << Pereira.recup_nom() << " " << Pereira.recup_prenom() << endl;
                }
                if(NumeroCompte != CompteSungur1.recup_num_Compte() && NumeroCompte != ComptePereira1.recup_num_Compte())
                {
                    cout << "Ce numéro de compte n'existe pas" << endl;
                }
                break;

            case 6:

                cout << "Nom: " << Guillaume.recup_nom() << endl;
                cout << "Prénom: " << Guillaume.recup_prenom() << endl;
                cout << "Votre RIB: " << CompteGuillaume1.recup_RIB() << endl;
                break;

            case 7: 

            if (CompteGuillaume1.recup_chequier() == 1)
            {
                cout << "Vous avez un chéquier" << endl;
            }
            if(CompteGuillaume1.recup_chequier() == 0)  
            {
                cout << "Vous n'avez pas de chéquier" << endl;
                cout << "Voulez-vous en acheter un ? (1 pour oui, 0 pour non) ";
                cin >> choix;
                if (choix == 1)
                {
                    CompteGuillaume1.commdander_chequier();
                    cout << "\nVous avez commander un chéquier" << endl;

                }

                if (choix == 0)
                {
                    cout << "\nVous n'avez pas commander de chéquier" << endl;
                }
            }

            break;

            case 8:

                boucle = 1;
                break;

            default:
                cout << "Choix invalide" << endl;
                break;
            }
            cout << "\nAppuyez sur Entrée pour continuer..." << endl;
            cin.ignore();
            cin.get();
            
            }
        }
        else if (NumeroCompte == CompteSungur1.recup_num_Compte() && CodeSecure == Sungur.recup_code_Securite())
        {

            while(boucle != 1)
        {
            cout << "\nBienvenue " << Sungur.recup_nom() << " " << Sungur.recup_prenom() << " !" << endl << endl;
            switch (Sungur.menu_client())
            {
            case 1:
                    Sungur.afficher();
                    break;
            
            case 2:

                cout << "Le solde de votre compte est de " << CompteSungur1.recup_solde() << " euros" << endl;
                break;

            case 3:

                cout << "Entrez le montant à déposer : ";
                cin >> montant;
                CompteSungur1.Crediiter(montant);
                cout << "'Vous avez déposé " << montant << " euros" << endl;
                cout << "Votre nouveau solde est de " << CompteSungur1.recup_solde() << " euros" << endl;
                break;
            
            case 4:

                cout << "Entrez le montant à retirer : ";
                cin >> montant;
                CompteSungur1.Debiter(montant);
                cout << " Vous avez retiré " << montant << " euros" << endl;
                cout << "Votre nouveau solde est de " << CompteSungur1.recup_solde() << " euros" << endl;
                break;

            case 5:

                cout << "Vous avez choisi l'option 5" << endl;
                break;

            case 6:

                cout << "Nom: " << Sungur.recup_nom() << endl;
                cout << "Prénom: " << Sungur.recup_prenom() << endl;
                cout << "Votre RIB: " << CompteSungur1.recup_RIB() << endl;
                break;

            case 7: 

            if (CompteSungur1.recup_chequier() == 1)
            {
                cout << "Vous avez un chéquier" << endl;
            }
            if(CompteSungur1.recup_chequier() == 0)  
            {
                cout << "Vous n'avez pas de chéquier" << endl;
                cout << "Voulez-vous en acheter un ? (1 pour oui, 0 pour non) ";
                cin >> choix;
                if (choix == 1)
                {
                    CompteSungur1.commdander_chequier();
                    cout << "\nVous avez commander un chéquier" << endl;

                }

                if (choix == 0)
                {
                    cout << "\nVous n'avez pas commander de chéquier" << endl;
                }
            }

            break;

            case 8:

                boucle = 1;
                break;

            default:
                cout << "Choix invalide" << endl;
                break;
            }
            cout << "\nAppuyez sur Entrée pour continuer..." << endl;
            cin.ignore();
            cin.get();
            
            }
        }
        else if (NumeroCompte == ComptePereira1.recup_num_Compte() && CodeSecure == Pereira.recup_code_Securite()) 
        {

            while(boucle != 1)
        {
            cout << "\nBienvenue " << Pereira.recup_nom() << " " << Pereira.recup_prenom() << " !" << endl << endl;
            switch (Pereira.menu_client())
            {
            case 1:

                    Pereira.afficher();
                    break;
            
            case 2:

                cout << "Le solde de votre compte est de " << ComptePereira1.recup_solde() << " euros" << endl;
                break;

            case 3:

                cout << "Entrez le montant à déposer : ";
                cin >> montant;
                ComptePereira1.Crediiter(montant);
                cout << "'Vous avez déposé " << montant << " euros" << endl;
                cout << "Votre nouveau solde est de " << ComptePereira1.recup_solde() << " euros" << endl;
                break;
            
            case 4:

                cout << "Entrez le montant à retirer : ";
                cin >> montant;
                ComptePereira1.Debiter(montant);
                cout << " Vous avez retiré " << montant << " euros" << endl;
                cout << "Votre nouveau solde est de " << ComptePereira1.recup_solde() << " euros" << endl;
                break;

            case 5:

                cout << "Quel est le montant à transférer ? ";
                cin >> montant;
                CompteGuillaume1.Debiter(montant);
                cout << " A qui voulez-vous transférer ? ";
                cin >> NumeroCompte;
                if(NumeroCompte == ComptePereira1.recup_num_Compte())
                {
                    cout << "Vous ne pouvez pas transférer de l'argent sur votre propre compte" << endl;
                }
                if (NumeroCompte == CompteGuillaume1.recup_num_Compte())
                {
                    CompteSungur1.Crediiter(montant);
                    cout << "Vous avez transféré " << montant << " euros à " << Guillaume.recup_nom() << " " << Guillaume.recup_prenom() << endl;
                }
                if (NumeroCompte == ComptePereira1.recup_num_Compte())
                {
                    ComptePereira1.Crediiter(montant);
                    cout << "Vous avez transféré " << montant << " euros à " << Sungur.recup_nom() << " " << Sungur.recup_prenom() << endl;
                }
                if(NumeroCompte != CompteSungur1.recup_num_Compte() && NumeroCompte != CompteGuillaume1.recup_num_Compte())
                {
                    cout << "Ce numéro de compte n'existe pas" << endl;
                }
                break;

            case 6:

                cout << "Nom: " << Pereira.recup_nom() << endl;
                cout << "Prénom: " << Pereira.recup_prenom() << endl;
                cout << "Votre RIB: " << ComptePereira1.recup_RIB() << endl;
                break;

            case 7: 

            if (ComptePereira1.recup_chequier() == 1)
            {
                cout << "Vous avez un chéquier" << endl;
            }
            if(ComptePereira1.recup_chequier() == 0)  
            {
                cout << "Vous n'avez pas de chéquier" << endl;
                cout << "Voulez-vous en acheter un ? (1 pour oui, 0 pour non) ";
                cin >> choix;
                if (choix == 1)
                {
                    ComptePereira1.commdander_chequier();
                    cout << "\nVous avez commander un chéquier" << endl;

                }

                if (choix == 0)
                {
                    cout << "\nVous n'avez pas commander de chéquier" << endl;
                }
            }
            break;

            case 8:
                boucle = 1;
                break;
                
            default:
                cout << "Choix invalide" << endl;
                break;
            }
            cout << "\nAppuyez sur Entrée pour continuer..." << endl;
            cin.ignore();
            cin.get();

        }
        }
        else 
        {
            cout << "Numéro de compte ou code de sécurité incorrect" << endl;
        }
        break;

    case 2:
    cout << "Au revoir" << endl;
    return 0;
    break;

    default:
    cout << "Choix invalide" << endl;
    break;

    }
}

    return 0;
}
