/** @file List.hpp 
 Fichier contenant les entêtes de fonctions et procédures
 
 @author Francis Delaney
 @author Francois Chantal
 @date 24 avril 2014
 @version 1.0 
*/

/*
constructeur de list
*/
template <class TYPE>
List<TYPE>::List()
    {
    first = NULL;
    last = NULL;
    nbElements = 0;
    }

/*
destructeur de list
*/
template <class TYPE>
List<TYPE>::~List()
    {
    this->Clear();
    }

/*
insert des elements a la fin de la list (supporte l'ajout dans une liste vide)
@param[in] _element element à ajouter
*/
template <class TYPE>
void List<TYPE>::PushBack(TYPE* _element)//Insert à la fin de liste (supporte l'ajout dans une liste vide)
    {
    if (first == NULL)
        {
        last = new Cell<TYPE>(_element,NULL,NULL);
        first = last;
        nbElements ++;
        }
    else
        {
        last = new Cell<TYPE>(_element,last,NULL);
        last->Previous->Next = last;
        nbElements ++;
        }
    }

/*
insert a un endroit precis dans la list (pas la fin)
@param[in] _element l'element a ajouter
@param[in] _iter l'emplacement ou ajouter l'element
*/
template <class TYPE>
void List<TYPE>::Insert(TYPE* _Element, Iterator<TYPE>& _Iter)
    {
    //Insert avant la position courante (limite: impossible d'ajouter à la fin!)
    //Ne supporte pas l'ajout dans une liste vide.
    //2 cas 1)Insertion au début
    //      2)Insertion entre premier et dernier
    if (_Iter.GetCurrent()->Previous == NULL)
        {
        first = new Cell<TYPE>(_Element,NULL,first);
        first->Next->Previous = first;
        nbElements ++;
        }
    else
        {
        Cell<TYPE>* cell = new Cell<TYPE>(_Element,_Iter.GetCurrent()->Previous,_Iter.GetCurrent());
        cell->Previous->Next = cell;
        cell->Next->Previous = cell;
        nbElements ++;
        }
    }
/*
enleve un noeud precis
@param[in] _iter l'emplacement du noeud a enlever
*/
template <class TYPE>
void List<TYPE>::Erase(Iterator<TYPE>& _Iter)
    {
    if (_Iter.GetCurrent()->Next != NULL && _Iter.GetCurrent()->Previous != NULL)// delete if dans le milieu
        {
        Cell<TYPE>* cell = _Iter.GetCurrent();

        _Iter.GetCurrent()->Next->Previous = _Iter.GetCurrent()->Previous;
        _Iter.GetCurrent()->Previous->Next = _Iter.GetCurrent()->Next;

        _Iter.Previous();
        delete  cell;
        nbElements --;
        }
    else if (_Iter.GetCurrent()->Next == NULL && _Iter.GetCurrent()->Previous == NULL)// delete if han solo
        {
        delete _Iter.GetCurrent();
        first = NULL;
        last =NULL;
        nbElements --;
        }
    else if (_Iter.GetCurrent()->Previous == NULL)// delete first
        {
        _Iter.Next();
        delete _Iter.GetCurrent()->Previous;
        first = _Iter.GetCurrent();
        first->Previous = NULL;
        nbElements --;
        }
    else if (_Iter.GetCurrent()->Next == NULL) // delete last
        {
        _Iter.Previous();
        delete _Iter.GetCurrent()->Next;
        last = _Iter.GetCurrent();
        last->Next = NULL;
        nbElements --;
        }
    }
/*
retourne l'element du noeud pointé
@param[in] _iter la position du noeud
@return l'element du noeud pointé
*/
template <class TYPE>
TYPE* List<TYPE>::GetElement(const Iterator<TYPE>& _Iter) const
    {
    return _Iter.GetCurrentElement();
    }
/*
retourne le nombre d'element dans la list
@return le nombre d'element dans la list
*/
template <class TYPE>
int List<TYPE>::GetNbElements() const
    {
    return nbElements;
    }
/*
verifie si la list est vide
@return si la list est vide
*/
template <class TYPE>
bool List<TYPE>::IsEmpty() const
    {
    return (first == NULL);
    }
/*
vide la list
*/
template <class TYPE>
void List<TYPE>::Clear()
    {
    Cell<TYPE>* cell;
    while (first != NULL)
        {
        cell = first;
        first = first->Next;
        delete cell;
        }
    last = NULL;
    }

//Méthodes déjà implémentées
template <class TYPE>
Cell<TYPE>* List<TYPE>::Begin() const
    {
    return this->first;
    }

template <class TYPE>
Cell<TYPE>* List<TYPE>::End() const
    {
    return this->last;
    }

template <class TYPE>
ostream& operator<<(ostream& _sortie, const List<TYPE>& _list)
    {
    Cell<TYPE>* cellule=_list.first;

    while(cellule != NULL){
        _sortie<<*cellule->Element<<endl;
        cellule = cellule->Next;
        }
    _sortie<<endl;
    return _sortie;
    }