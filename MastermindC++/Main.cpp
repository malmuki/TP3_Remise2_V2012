// Mastermind.cpp : Defines the entry point for the console application.
//
#include <tchar.h>
#include <string>

#include "ConsoleMenu.h"

using namespace std;


void main(int argc, _TCHAR* argv[])
{
    if (argc == 2){ 
        string parametre = argv[1];
        if(parametre == "-auteur" || parametre == "-a"){
            cout<<"[Vos noms], tout droit réservé, 2013."<<endl;
            return;
        }
    }
        
    ConsoleMenu console;
    console.Run();
    
    return;
}
