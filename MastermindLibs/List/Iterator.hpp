/** @file Iterator.hpp 
 Fichier contenant les entêtes de fonctions et procédures
 
 @author Francis Delaney
 @author Francois Chantal
 @date 24 avril 2014
 @version 1.0 
*/

/*
constructeur d'Iterator
*/
template <class TYPE>
Iterator<TYPE>::Iterator(void)
    {
    }
/*
change le current de l'iterator au prochain
*/
template <class TYPE>
void Iterator<TYPE>::Next(void)
    {
    current = current->Next;
    }
/*
change le current de l'iterator au precedant
*/
template <class TYPE>
void Iterator<TYPE>::Previous(void)
    {
    current = current->Previous;
    }
/*
retourne l'element courrant
@return l'element courrant
*/
template <class TYPE>
TYPE* Iterator<TYPE>::GetCurrentElement(void) const
    {
    return current->Element;
    }
/*
retourne le noeud courrant
@return le noeud courrant
*/
template <class TYPE>
Cell<TYPE>* Iterator<TYPE>::GetCurrent(void) const
    {
    return current;
    }
/*
change le noeud courrant
@param[in] _cell le nouveau noeud courrant
*/
template <class TYPE>
void Iterator<TYPE>::SetCurrent(Cell<TYPE>* _cell)
    {
    current = _cell;
    }