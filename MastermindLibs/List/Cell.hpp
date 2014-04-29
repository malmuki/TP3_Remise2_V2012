/** @file Cell.hpp 
 Fichier contenant les entêtes de fonctions et procédures 
 @author Francis Delaney
 @author Francois Chantal
 @date 24 avril 2014
 @version 1.0 
*/


/*
Constructeur de cell
@param[in] _element c'est l'element vers lequel la cell va pointer
@param[in] _previous noeud precedant
@param[in] _next noeud suivant
*/
template <class TYPE>
Cell<TYPE>::Cell(TYPE* _element, Cell* _previous, Cell* _next)
{
    this->Element = _element;
    this->Previous= _previous;
    this->Next = _next;
}