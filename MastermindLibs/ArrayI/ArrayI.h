#pragma once

#include <iostream>
using namespace std;

template <class TYPE>
class ArrayI
{
public:
    ArrayI(int _nbElements);
    ~ArrayI(void);

    int GetNbElements() const;
    TYPE GetElement(const int &_position) const;
    void SetElement(const TYPE &_element, const int &_position);

    //Surcharges
    TYPE& operator[](const int& _position);
    void operator=(const ArrayI<TYPE> &_arrayI);

    template <class TYPE>
    friend ostream& operator<<(ostream& _sortie, const ArrayI<TYPE> &_arrayI);

private:
    ArrayI(ArrayI&); //Copieur désactivé
    //static const int NB_ELEMENTS = 100;
    int nbElements;
    TYPE* tab;
};

#include "ArrayI.hpp"
























//int rechercheDichoRec(TYPE element, int deb, int fin) {
//    if(deb > fin) return -1;
//
//    int milieu = (deb + fin)/2 ;
//
//    TYPE e = _pTab[milieu] ;
//
//    if(e==element)
//        return (milieu); //On a trouvé!
//    else if (e<element)
//        return (rechercheDicho(element, milieu+1, fin));
//    else
//        return(rechercheDicho(element, deb, milieu-1));
//}


//Quick Sort: Diviser pour mieux règner!
//
//Algorithme:
//Déterminer PIVOT (sépare le pTab en 2), 
//         ->On fait passer à droite du PIVOT les valeurs plus grandes
//         ->On fait passer à gauche du PIVOT les valeurs plus petites
//       ->On recommence avec la partie de gauche
//         ->On recommence avec la partie de droite
// et MAGIE!

//void quickSort(TYPE *pTab, int premier, int dernier) {
//    static int numAppel=0;
//    numAppel++;
//
//
//    //Affichage du tableau a traiter
//    for(int i = premier; i<= dernier; i++){
//        if(i==premier) cout<<"Appel de quickSort "<<numAppel<<endl;
//            
//        cout<<pTab[i]<<" ";
//
//        if(i==dernier) cout<<endl;
//    }
//        
//    int indexPivot;
//
//    //Si la partie est trop petite pour être triée, on doit rien faire
//    if(premier<dernier) {
//
//        indexPivot = partitionner(pTab, premier, dernier); //Détermine le prochain PIVOT, tout ce qui est à droite de ce PIVOT est plus grand ou égale à ce qui se trouve à gauche
//
//        /*Tout ce qui est plus petit se retrouve à gauche (incluant le pivot) du tableau
//        et tout ce qui est plus grand se retrouve à droite (exluant le pivot) du tableau */
//
//        quickSort(pTab, premier, indexPivot); //On recommence avec la partie de gauche (inclut le PIVOT car il n'est pas nécessairement le plus grand même s'il est placé à la dernière postion)
//        quickSort(pTab, indexPivot+1, dernier);  //On recommence avec la partie de droite (exclut le PIVOT)
//    }
//}
     
//Place tout ce qui est plus petit que le PIVOT (premier élément) à gauche de tout ce qui est plus grand que le PIVOT.
//Détermine le nouveau PIVOT, il correspond à la premier valeur plus petite que le PIVOT en partant de la fin
//int partitionner(TYPE *pTab, int premier, int dernier) {
//    const int pivot = pTab[premier]; //Le PIVOT est le premier élément du tableau pTab (sous tableau de QuickSort)
//    int gauche = premier-1; //Itérateur à partir du début
//    int droite = dernier+1; //Itérateur à partir de la fin
//    while(true) {
//        do
//            droite--;
//        while(pTab[droite] > pivot); //Les éléments plus grands que le PIVOT (premier élément) en partant de la droite ne sont pas déplacés.
//
//        do
//            gauche++;
//        while(pTab[gauche] < pivot); //Les éléments plus petits que le PIVOT (premier élément) en partant de la gauche ne sont pas déplacés.
//
//        if(gauche<droite) //Si un élément plus grand se trouve à gauche d'un élément plus petit, on les permute
//            permuter(pTab[gauche], pTab[droite]);
//        else
//            return droite;  //L'élément plus grand se trouve à la droite du plus petit, ce dernier (le plus petit) est le prochain PIVOT
//    }
//}



//Surcharges
//TYPE& operator[](const int& position){
//    assert(position>=0 && position<_nbElements);
//    return _pTab[position];
//}
//
//void operator=(const tabSafe<TYPE>& p){ //Affectateur
//    delete[] _pTab; //Libere la mémiore en premier
//
//    _pTab = new TYPE[p._nbElements];
//        
//    //Copie des valeurs
//    for(int i=0;i<p._nbElements;i++){
//        _pTab[i]=p._pTab[i];
//    }
//}
//friend ostream& operator<<(ostream& sortie, const tabSafe& t){
//    for(int i=0;i<t._nbElements;i++){
//        sortie<<"["<<i<<"]: "<<t._pTab[i]<<endl;
//    }
//    return sortie;
//}
