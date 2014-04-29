#include "Mastermind.h"


Mastermind::Mastermind()
{
   //Il faut créer ici les 4096 séquences de couleurs possibles. Bonne réflexion!
}

Mastermind::~Mastermind()
{
}

int Mastermind::GetNbElements() const
{
    return 1;
}


ArrayI<Color>* Mastermind::GetElement() const
{
    //Utiliser la classe RandomNumber pour ne pas offrir toujours le premier élément de la liste (les parties seraient toutes pareilles avec la même séquence cachée)
    ArrayI<Color>* PourCompiler;
    return PourCompiler;
}

short Mastermind::CleanList(Color* _tabColorRef, short* _tabVerdicts) //return le nb d'element deleter
{

     /*switch(tabVerdicts[i]){
                
                case 1: //Bonne couleur, bonne place

                        //Si la séquence de couleurs traitée n'a pas la couleur à la bonne place, il faut la retirer de la liste.

                case 2: //Bonne couleur, mauvaise place

                        //Si la séquence de couleurs traitée n'a pas la couleur à un autre emplacement que celui de la couleur de référence,
                        //il faut la retirer de la liste.
           
                case 3: //Mauvaise couleur
                        //Si la séquence de couleurs traitée a la couleur, il faut la retirer de la liste.
    };*/
    return 1; //Pour Compiler
}