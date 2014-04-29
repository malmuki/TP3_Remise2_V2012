// This is the main DLL file.

#include "stdafx.h"
#include "Mastermind.h"
#include "MastermindCLR.h"


//Constructeur
MastermindCLR::Ordinateur::Ordinateur()
{
    this->mastermind = new Mastermind();
}
//Destructeur
MastermindCLR::Ordinateur::~Ordinateur()
{
    delete this->mastermind;
}

void MastermindCLR::Ordinateur::genererSequence()
{

    ArrayI<Color>* sequence;
    sequence = this->mastermind->GetElement();

    this->c1 = (*sequence)[0].GetColor();
    this->c2 = (*sequence)[1].GetColor();
    this->c3 = (*sequence)[2].GetColor();
    this->c4 = (*sequence)[3].GetColor();
        
}

int MastermindCLR::Ordinateur::getCouleur1()
{
    return this->c1;
}
int MastermindCLR::Ordinateur::getCouleur2()
{
    return this->c2;
}
int MastermindCLR::Ordinateur::getCouleur3()
{
    return this->c3;
}
int MastermindCLR::Ordinateur::getCouleur4()
{
    return this->c4;
}

void MastermindCLR::Ordinateur::epurerListe(int _c1, //4 couleurs de référence
                                            int _c2,
                                            int _c3,
                                            int _c4, 
                                            int _v1, //4 verdicts
                                            int _v2,
                                            int _v3,
                                            int _v4)
{

    Color tabCouleurs[4];
    tabCouleurs[0] = _c1;
    tabCouleurs[1] = _c2;
    tabCouleurs[2] = _c3;
    tabCouleurs[3] = _c4;

    short tabVerdicts[4];
    tabVerdicts[0] = (short) _v1;
    tabVerdicts[1] = (short) _v2;
    tabVerdicts[2] = (short) _v3;
    tabVerdicts[3] = (short) _v4;

    this->mastermind->CleanList(tabCouleurs, tabVerdicts);

}