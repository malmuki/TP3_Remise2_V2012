/* @file ConsoleMenu.cpp
Fichier contenant les definitions de fonctions et procédures.
@author   Francois Chantal
@author   Francis Delaney
@date     13 mai 2014
@version  1.0 */

#include "ConsoleMenu.h"
#include "Mastermind.h"
#include "MasterMindColor.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <tchar.h>

#include <windows.h> //Pour la fonction CharToOem ->Propriétédu projet "Jeu de caractères" doit être à "Non défini"

using namespace std;

/*
Fonction d'entrer du programe qui declare les valeurs valides de la console
est aussi la boucle pricipale du programe
*/
void ConsoleMenu::Run()
    {
    char input;
    char tabValidInputs[] = {'1','2','3'};
    const int NB_ELEMENTS = 3;
    do{
        system("cls");
        input = readValidInput(tabValidInputs, NB_ELEMENTS);
        }while(manageChoice(input));
    }
/*
Fonction qui determine quoi faire tel ou tel operation si une touche valide est entré
@param[in] _input c'est une entrée clavier verifiée
@return retourne si le choix etais celui de sortie du progrma
*/
bool ConsoleMenu::manageChoice(char _input)
    {
    bool choix = true;
    if(_input == '0')
        {
        choix = false;
        }else
        {
        menu();
            }
return choix;
    }

    /*
    Fonction qui determine si l'entré clavier est valide ou non et boucle si invalide
    @param[in] _tabValidInputs[] le tableau contenant les entrés permises
    @param[in] _nbElements le nombre d'element dans _tabValidInputs[]
    @return un choix utilisateur valide en CHAR
    */
    char ConsoleMenu::readValidInput(char  _tabValidInputs[], int _nbElements)
        {
        string input;
        bool valid = false;

        displayMenu();

        do {
            getline(cin, input);
            for (int i = 0; i < _nbElements; i++)
                {
                if (_tabValidInputs[i] == input[0])
                    {
                    valid = true;
                    }
                }
            if (!valid){
                cout << "le type d'entré est invalide!";
                }
            }while(!valid);
        return input[0];
        }

    /*
    fonction qui affiche le menu du programe
    */
    void ConsoleMenu::displayMenu()
        {
        cout<<string("Veuillez entrer une séquence de 4 couleurs parmis les suivantes:")<<endl<<endl;
        cout<<"    1-Rouge"<<endl;
        cout<<"    2-Vert"<<endl;
        cout<<"    3-Bleu"<<endl;
        cout<<"    4-Jaune"<<endl;
        cout<<"    5-Noir"<<endl;
        cout<<"    6-Orange"<<endl;
        cout<<"    7-Mauve"<<endl;
        cout<<"    8-Blanc"<<endl;
        }

    void ConsoleMenu::menu()
        {
        Mastermind mastermind;

        Color tabCouleurs[4]; //4 couleurs parmis un choix de 8

        if(!colorSelection(tabCouleurs))return;

        cout<<"Couleurs choisies: "<<tabCouleurs[0] <<" "
            <<tabCouleurs[1] <<" "
            <<tabCouleurs[2] <<" "
            <<tabCouleurs[3] <<" "
            <<endl;

        short nbCoups=0;

        cout<<endl<<endl<<string("##############################Début de la partie##############################")<<endl<<endl;
        while(true){
            if(nbCoups==8){
                cout<<string("Le nombre maximum d'essais a atteind la limite (8). Je perds...")<<endl<<endl;
                break;
                }
            int iNbElements=mastermind.GetNbElements();
            if (iNbElements==0){ //Il ne reste plus de combinaison dans la liste, l'utilisateur a fait assurément une erreur car HAL ne se trompe pas!
                cout<<string("La liste de combinaisons possibles est épuisée.")<<endl<<endl;;
                break;
                }
            nbCoups++;

            cout<<string("NbElements:")<<iNbElements<<endl;

            //Obtention de la combinaison de couleur de référence
            ArrayI<Color>* tabCouleursRef = mastermind.GetElement();

            cout<<string("--------Couleurs à deviner: ")<<tabCouleurs[0] <<" "
                <<tabCouleurs[1] <<" "
                <<tabCouleurs[2] <<" "
                <<tabCouleurs[3] <<" "
                <<"--------"
                <<endl;

            cout<<endl<<"Choix de HAL ("<<string("essai #")<<nbCoups<<"):    " <<(*tabCouleursRef)[0] <<" "
                <<(*tabCouleursRef)[1] <<" "
                <<(*tabCouleursRef)[2] <<" "
                <<(*tabCouleursRef)[3] <<" "
                <<endl<<endl;

            short tabVerdicts[4];

            //Lecteur des 4 verdicts de l'usager
            for(int i=0;i<4;i++){
                do{
                    string entree;

                    //Couleur c=(*t)[0]; //Si la liste retourne un pointeur
                    Color c = (*tabCouleursRef)[i];

                    cout<<endl<<"Couleur "<<i+1<<" - "<<(*tabCouleursRef)[i]<<endl;
                    cout<<"Choisir (1-Bonne place 2-Bonne couleur 3-Mauvaise couleur): ";

                    cin>>entree;
                    tabVerdicts[i] = atoi(entree.c_str());
                    }while (tabVerdicts[i]!=1 && tabVerdicts[i]!=2 && tabVerdicts[i]!= 3);
                }

            if(tabVerdicts[0]==1 && tabVerdicts[1]==1 && tabVerdicts[2]== 1 && tabVerdicts[3]== 1){
                cout<<endl<<string("J'ai trouvé la réponse après ")<<nbCoups;
                if(nbCoups==1){
                    cout<<string(" essai. Merci d'avoir joué avec moi.")<<endl<<endl;
                    }
                else{
                    cout<<string(" essais. Merci d'avoir joué avec moi.")<<endl<<endl;
                    }
                break;
                }

            //------------------------Epuration de la liste des combinaisons qui ne respectent pas les critères-----------------------------
            Color temp[4];
            temp[0] = (*tabCouleursRef)[0];
            temp[1] = (*tabCouleursRef)[1];
            temp[2] = (*tabCouleursRef)[2];
            temp[3] = (*tabCouleursRef)[3];

            cout<<mastermind.CleanList(temp, tabVerdicts)<<string(" combinaisons supprimées.")<<endl;
            }
        }

    bool ConsoleMenu::colorSelection(Color *_tabCouleurs)
        {
        string choix;
        do{
            cout<<"Entrer la suite de chiffres, 0 pour sortir: ";
            cin>>choix;
            if (choix == "0")
                {
                return false;
                }
            if(choix.length()==4){
                _tabCouleurs[0].SetColor(atoi(choix.substr(0,1).c_str()));
                _tabCouleurs[1].SetColor(atoi(choix.substr(1,1).c_str()));
                _tabCouleurs[2].SetColor(atoi(choix.substr(2,1).c_str()));
                _tabCouleurs[3].SetColor(atoi(choix.substr(3,1).c_str()));
                }
            }while(choix.length()!=4 || _tabCouleurs[0]>8 || _tabCouleurs[1] > 8 || _tabCouleurs[2] > 8 || _tabCouleurs[3] > 8);

        return true;
        }