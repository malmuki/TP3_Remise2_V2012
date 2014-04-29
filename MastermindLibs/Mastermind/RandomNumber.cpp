#include <iostream>
#include <time.h> 
#include <stdio.h> //Pour avoir fonciton srand()
#include "RandomNumber.h"


RandomNumber::RandomNumber(void)
{
    time_t time(time_t *tloc);
    srand((unsigned int)time(NULL)+100);  // On part la séquence à l'aide d'un nombre alléatoire (basé sur le temps)
}

int RandomNumber::GetNumber(short _max)
{
    return (rand() % _max) + 1; //Le nombre généré sera entre 1 et _max
}

RandomNumber::~RandomNumber(void)
{
}
