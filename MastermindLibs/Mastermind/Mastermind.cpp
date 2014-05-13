#include "Mastermind.h"


Mastermind::Mastermind()
{
	//Il faut cr�er ici les 4096 s�quences de couleurs possibles. Bonne r�flexion!
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
	//Utiliser la classe RandomNumber pour ne pas offrir toujours le premier �l�ment de la liste (les parties seraient toutes pareilles avec la m�me s�quence cach�e)
	RandomNumber index;
	Iterator<ArrayI<Color>> iter;
	iter.SetCurrent(list->Begin());

	for(int i=1; i<index.GetNumber(GetNbElements()); i++)
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
	bool deleted;
	bool toBeDeleted;
	short deletedElements = 0;

	while(iter.GetCurrent() != NULL)
	{
		deleted = false;
		for(int j = 0; j<4; j++)
		{
			switch(_tabVerdicts[j])
			{

			case 1: //Bonne couleur, bonne place

				//Si la s�quence de couleurs trait�e n'a pas la couleur � la bonne place, il faut la retirer de la liste
				if(iter.GetCurrentElement()->GetElement(j) != _tabColorRef[j])
				{
					list->Erase(iter);
					deleted = true;
					deletedElements ++;
				}
				break;

			case 2: //Bonne couleur, mauvaise place

				//Si la s�quence de couleurs trait�e n'a pas la couleur � un autre emplacement que celui de la couleur de r�f�rence,
				//il faut la retirer de la liste.
				toDelete = true;
				toBeDeleted = false;
				for(int k=0; k<4; k++)
				{
					if(iter.GetCurrentElement()->GetElement(k) == _tabColorRef[j] && k != j && !toBeDeleted)
					{
						toDelete = false;
					}
					else if(iter.GetCurrentElement()->GetElement(k) == _tabColorRef[j] && k == j)
					{
						toDelete = true;
						toBeDeleted = true;
					}
				}
				if(toDelete)
				{
					list->Erase(iter);
					deleted = true;
					deletedElements ++;
				}
				break;
			case 3: //Mauvaise couleur
				//Si la s�quence de couleurs trait�e a la couleur, il faut la retirer de la liste.
				toDelete = false;
				for(int k=0; k<4; k++)
				{
					if(iter.GetCurrentElement()->GetElement(k) == _tabColorRef[j])
					{
						toDelete = true;
					}
				}
				if(toDelete)
				{
					list->Erase(iter);
					deleted = true;
					deletedElements ++;
				}
				break;
			}

		}
		if(!deleted)
		{
			iter.Next();
		}

	}
	return deletedElements;
}