// Mastermind.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
//#include <time.h>
#include <iostream>
#include <string>
using namespace std;

#include <windows.h> //Pour la fonction CharToOem ->Propriétédu projet "Jeu de caractères" doit être à "Non défini"

#include "Mastermind.h"

string accents(const string &pString){

    assert(pString.length()<=1024);
    char source[1024]; //Propriétés du projet "Characters set" doit être à "Not set" -> pas de caractère UNICODE)
    strcpy_s(source, 1024, pString.c_str());
    char destination[sizeof(source)];
    CharToOem(source, destination);
    return destination;
}


void main(int argc, _TCHAR* argv[])
{
    if (argc == 2){ 
        string parametre = argv[1];
        if(parametre == "-auteur" || parametre == "-a"){
            cout<<"[Vos noms], tout droit réservé, 2013."<<endl;
            return;
        }
    }
    
    while(true){
        
        Mastermind mastermind;
        
        Color tabCouleurs[4]; //4 couleurs parmis un choix de 8
        
        cout<<accents("Veuillez entrer une séquence de 4 couleurs parmis les suivantes:")<<endl<<endl;
        cout<<"    1-Rouge"<<endl;
        cout<<"    2-Vert"<<endl;
        cout<<"    3-Bleu"<<endl;
        cout<<"    4-Jaune"<<endl;
        cout<<"    5-Noir"<<endl;
        cout<<"    6-Orange"<<endl;
        cout<<"    7-Mauve"<<endl;
        cout<<"    8-Blanc"<<endl;

        string choix;
        do{
            cout<<"Entrer la suite de chiffres, 0 pour sortir: ";
            cin>>choix;
            if(choix=="0")return;
            if(choix.length()==4){
                tabCouleurs[0].SetColor(atoi(choix.substr(0,1).c_str()));
                tabCouleurs[1].SetColor(atoi(choix.substr(1,1).c_str()));
                tabCouleurs[2].SetColor(atoi(choix.substr(2,1).c_str()));
                tabCouleurs[3].SetColor(atoi(choix.substr(3,1).c_str()));
            }
        }while(choix.length()!=4 || tabCouleurs[0]>8 || tabCouleurs[1] > 8 || tabCouleurs[2] > 8 || tabCouleurs[3] > 8);

        cout<<"Couleurs choisies: "<<tabCouleurs[0] <<" "
                                   <<tabCouleurs[1] <<" "
                                   <<tabCouleurs[2] <<" "
                                   <<tabCouleurs[3] <<" "
                                   <<endl;


        short nbCoups=0;

        cout<<endl<<endl<<accents("##############################Début de la partie##############################")<<endl<<endl;
        while(true){

            if(nbCoups==8){
                cout<<accents("Le nombre maximum d'essais a atteind la limite (8). Je perds...")<<endl<<endl; 
                break;
            }
            int iNbElements=mastermind.GetNbElements();
            if (iNbElements==0){ //Il ne reste plus de combinaison dans la liste, l'utilisateur a fait assurément une erreur car HAL ne se trompe pas!
                cout<<accents("La liste de combinaisons possibles est épuisée.")<<endl<<endl;; 
                break;
            }
            nbCoups++;

            
            cout<<accents("NbElements:")<<iNbElements<<endl;

            //Obtention de la combinaison de couleur de référence
            ArrayI<Color>* tabCouleursRef = mastermind.GetElement();

            cout<<accents("--------Couleurs à deviner: ")<<tabCouleurs[0] <<" "
                                                         <<tabCouleurs[1] <<" "
                                                         <<tabCouleurs[2] <<" "
                                                         <<tabCouleurs[3] <<" "
                                                         <<"--------"
                                                         <<endl;

            cout<<endl<<"Choix de HAL ("<<accents("essai #")<<nbCoups<<"):    " <<(*tabCouleursRef)[0] <<" "
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
                cout<<endl<<accents("J'ai trouvé la réponse après ")<<nbCoups;
                if(nbCoups==1){
                    cout<<accents(" essai. Merci d'avoir joué avec moi.")<<endl<<endl;
                }
                else{
                    cout<<accents(" essais. Merci d'avoir joué avec moi.")<<endl<<endl;
                }
                cout<<accents("----HAL 9000----")<<endl<<endl;
                break;
            }

            //------------------------Epuration de la liste des combinaisons qui ne respectent pas les critères-----------------------------
            Color temp[4];
            temp[0] = (*tabCouleursRef)[0];
            temp[1] = (*tabCouleursRef)[1];
            temp[2] = (*tabCouleursRef)[2];
            temp[3] = (*tabCouleursRef)[3];

            cout<<mastermind.CleanList(temp, tabVerdicts)<<accents(" combinaisons supprimées.")<<endl;
            
        }
    }
    return;
}
