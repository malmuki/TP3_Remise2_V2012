#pragma once

//Encapsule le problème de la génération d'un nombre alléatoire
class RandomNumber
{
public:
    RandomNumber(void);
    ~RandomNumber(void);

    int GetNumber(short _max);
};

