#pragma once
#include "MasterMindColor.h"

class ConsoleMenu
    {
    public:
        void Run();
    private:
        char readValidInput(char  _tabValidInputs[], int _nbElements);
        bool manageChoice(char _input);
        void displayMenu();
        bool colorSelection(Color *_tabColor);
        void menu();
    };

