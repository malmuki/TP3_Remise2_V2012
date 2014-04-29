#include "MasterMindColor.h"


Color::Color(void)
{
    this->color = 0;
}
Color::Color(short _c)
{
    this->color = _c;
}
Color::~Color(void){}

ostream& operator<<(ostream& sortie, const Color& _c)
{
    
    switch(_c.color){
        case 1:
            sortie<<"Rouge";
            break;
        case 2:
            sortie<<"Vert";
            break;
        case 3:
            sortie<<"Bleu";
            break;
        case 4:
            sortie<<"Jaune";
            break;
        case 5:
            sortie<<"Noir";
            break;
        case 6:
            sortie<<"Orange";
            break;
        case 7:
            sortie<<"Mauve";
            break;
        case 8:
            sortie<<"Blanc";
            break;
    };
    return sortie;
}

bool Color::operator==(const Color& _c)
{ 
    return this->color == _c.color;
}

bool Color::operator>(const Color& _c){ 
    return this->color > _c.color;
}

bool Color::operator<(const Color& _c){ 
    return this->color < _c.color;
}

bool Color::operator!=(const Color& _c){ 
    return this->color != _c.color;
}

void Color::operator=(const Color& _c){ 
    this->color = _c.color;
}

short Color::GetColor(){
    return this->color;
}

void Color::SetColor(short _c){
    this->color = _c;
}
