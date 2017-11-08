/**
* Max et Min d'une série.
* \fichier   Exercice4.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   11 octobre 2014
* Créé le 9 octobre 2014
*/

#include <iostream>

using namespace std;

int main()
{
	int note = 0,
		noteMax = 0,
		compteurMax = 1,
		noteMin = 20,
		compteurMin = 1;

	bool noteBonne = true;

	do
	{
		cout << "Entrez une note entre 0 et 20 (valeur negative pour terminer) : ";
		cin >> note;
		noteBonne = note >= 0 && note <= 20;

		if (note > noteMax && noteBonne)
		{
			noteMax = note;
			compteurMax = 1;
		}
		else if (note == noteMax)
		{
			compteurMax++;
		}

		if (note < noteMin && noteBonne)
		{
			noteMin = note;
			compteurMin = 1;
		}
		else if (note == noteMin)
		{
			compteurMin++;
		}
	} while (note >= 0);

	cout << "Note maximale : " << noteMax << " attribuee " << compteurMax << " fois." << endl;
	cout << "Note minimale : " << noteMin << " attribuee " << compteurMin << " fois." << endl;

	return 0;
}