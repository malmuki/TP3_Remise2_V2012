#pragma once
#include "RandomNumber.h"
#include "ArrayI.h"
#include "List.h"
#include "MasterMindColor.h"

class Mastermind
{
public:
    Mastermind();
    ~Mastermind();

    int GetNbElements() const;
    ArrayI<Color>* GetElement() const;

    //Épure la liste de séquences de couleurs en fonction de la séquence traitée et des 4 verdicts (valeurs 1 à 3) sur cette dernière.
    short CleanList(Color* _tabColorRef, short* _tabVerdicts);

private:
    List<ArrayI<Color>>* list; //Contient toutes les séquences de couleurs possibles, selon le contexte.
    ArrayI<Color>* tabSequences[4096]; //Pointeurs pour la destruction des 4096 séquences de couleurs créées sur le tas par le Mastermind::Mastermind() lors de la création de la liste.
};
