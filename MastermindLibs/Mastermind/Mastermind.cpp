#include "Mastermind.h"


Mastermind::Mastermind()
{
	//Il faut créer ici les 4096 séquences de couleurs possibles. Bonne réflexion!
	list = new List<ArrayI<Color>>;
	int compteur = 0;

	for (int i = 1 ; i<=8; i++)
	{
		for (int j = 1 ; j<=8; j++)
		{
			for (int k = 1 ; k<=8; k++)
			{
				for (int l = 1 ; l<=8; l++)
				{
					tabSequences[compteur] = new ArrayI<Color>(4);
					tabSequences[compteur]->SetElement(i,0);
					tabSequences[compteur]->SetElement(j,1);
					tabSequences[compteur]->SetElement(k,2);
					tabSequences[compteur]->SetElement(l,3);
					list->PushBack(tabSequences[compteur]);
					compteur++;
				}
			}
		}
	}
}

Mastermind::~Mastermind()
{
	delete list;

	for(int i=0; i<4096; i++)
	{
		delete tabSequences[i];
	}
}

int Mastermind::GetNbElements() const
{
	return list->GetNbElements();
}


ArrayI<Color>* Mastermind::GetElement() const
{
	//Utiliser la classe RandomNumber pour ne pas offrir toujours le premier élément de la liste (les parties seraient toutes pareilles avec la même séquence cachée)
	RandomNumber index;
	Iterator<ArrayI<Color>> iter;
	iter.SetCurrent(list->Begin());

	for(int i=0; i<index.GetNumber(GetNbElements()); i++)
	{
		iter.Next();
	}
	return iter.GetCurrentElement();
}

short Mastermind::CleanList(Color* _tabColorRef, short* _tabVerdicts) //return le nb d'element deleter
{
	Iterator<ArrayI<Color>> iter;
	iter.SetCurrent(list->Begin());
	bool toDelete;
	for(int i=0; i<GetNbElements(); i++)
	{

		for(int j = 0; j<4; j++)
		{
			switch(_tabVerdicts[j]){

			case 1: //Bonne couleur, bonne place

				//Si la séquence de couleurs traitée n'a pas la couleur à la bonne place, il faut la retirer de la liste
				if(iter.GetCurrent()->Element->GetElement(j) != _tabColorRef[j])
				{
					list->Erase(iter);
				}
				break;

			case 2: //Bonne couleur, mauvaise place

				//Si la séquence de couleurs traitée n'a pas la couleur à un autre emplacement que celui de la couleur de référence,
				//il faut la retirer de la liste.
				toDelete = true;
				for(int k=0; k<4; k++)
				{
					if(iter.GetCurrent()->Element->GetElement(k) == _tabColorRef[j])
					{
						toDelete = false;
					}
				}
				if(toDelete)
				{
					list->Erase(iter);
				}
				break;
			case 3: //Mauvaise couleur
				//Si la séquence de couleurs traitée a la couleur, il faut la retirer de la liste.
				toDelete = false;
				for(int k=0; k<4; k++)
				{
					if(iter.GetCurrent()->Element->GetElement(k) == _tabColorRef[j])
					{
						toDelete = true;
					}
				}
				if(toDelete)
				{
					list->Erase(iter);
				}
				break;
			}
		}
		iter.Next();
	}
	return 1; //Pour Compiler
}