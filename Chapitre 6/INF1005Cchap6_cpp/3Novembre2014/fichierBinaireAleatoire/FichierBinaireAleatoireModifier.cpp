// lire le fichier alea.bin
// trouver le nombde d'élement dans le fichier
// modifier une valeur dans le fichier
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
//  trouver le nombre d'élements dans le fichier alea.bin
//  afficher le contenu du fichier
//  demander un position dans le fichier
//  afficher la valeur à cette position
// demander un nouvelle valeur et l'écrire dans le fichier
//  afficher le contenur du fichier

int main()
{

	fstream lecture;
	int nbrElement, position, nouvelleValeur;
	int valeur;
	lecture.open("alea.bin", ios::in | ios::out | ios::binary);
	if (!lecture.fail())
	{
		lecture.seekg(0, ios::end);
		nbrElement = lecture.tellg() / sizeof(valeur);

		cout << nbrElement << endl;

		lecture.seekg(0, ios::beg);

		for (int i = 0; i < nbrElement; i++)
		{
			lecture.read((char*)& valeur, sizeof(valeur));
			cout << valeur << endl;
		}

		cout << "Entrer une position" << endl;
		cin >> position;

		if ((position < nbrElement) && (position >= 0))
		{
			lecture.seekg(position*sizeof(valeur), ios::beg);
			lecture.read((char*)& valeur, sizeof(valeur));
			cout << valeur << endl;

			cout << "Entrer une nouvelle valeur" << endl;
			cin >> valeur;

			lecture.seekp(-1 * streamoff(sizeof(valeur)), ios::cur);
			lecture.write((char*)& valeur, sizeof(valeur));

			lecture.seekg(0, ios::beg);

			for (int i = 0; i < nbrElement; i++)
			{
				lecture.read((char*)& valeur, sizeof(valeur));
				cout << valeur << endl;
			}
		}


	}
	else
		cout << "probleme avec le fichier" << endl;

	return 0;
}