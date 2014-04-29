#include <assert.h>


template <class TYPE>
ArrayI<TYPE>::ArrayI(int _nbElements)
{
    //Initialisation du tableau
    this->nbElements = _nbElements;
    this->tab = new TYPE[this->nbElements];
}

template <class TYPE>
ArrayI<TYPE>::~ArrayI(void)
{
    delete[] this->tab;
}

template <class TYPE>
int  ArrayI<TYPE>::GetNbElements() const
{
    return this->nbElements;
}

template <class TYPE>
TYPE ArrayI<TYPE>::GetElement(const int &_position) const
{
    assert(_position > -1 && _position < this->GetNbElements());
    return this->tab[_position];
}

template <class TYPE>
void ArrayI<TYPE>::SetElement(const TYPE &_element, const int &_position)
{
    assert(_position > -1 && _position < this->GetNbElements());
    this->tab[_position] = _element;

}
//Surcharges
template <class TYPE>
TYPE& ArrayI<TYPE>::operator[](const int& _position)
{
    assert(_position >= 0 && _position< this->GetNbElements());
    return this->tab[_position];
}

template <class TYPE>
void ArrayI<TYPE>::operator=(const ArrayI<TYPE> &_arrayI)
{ //Affectateur
    delete[] this->tab; //Libere la mémiore en premier

    this->tab = new TYPE[_arrayI.GetNbElements()];
        
    //Copie des valeurs
    for(int i=0; i < _arrayI.GetNbElements(); i++)
    {
        this->tab[i]= _arrayI.tab[i];
    }
}

template <class TYPE>
ostream& operator<<(ostream& _sortie, const ArrayI<TYPE> &_arrayI)
{
    for(int i=0; i < _arrayI.GetNbElements(); i++)
    {
        _sortie<<"["<<i<<"]: "<<_arrayI.tab[i]<<std::endl;
    }
    return _sortie;
}