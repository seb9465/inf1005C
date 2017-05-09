/**
* Différentes opérations sur un nombre.
* \fichier   Exercice1.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   11 octobre 2014
* Créé le 9 octobre 2014
*/

#include <iostream>

using namespace std;

int main()
{
	double nombre = 0.0,
		reponse = 0.0;
	char option = '0';

	cout << "Entrez un nombre : ";
	cin >> nombre;

	cout << "Choisir une option parmi les suivantes : " << endl
		<< "carree (option 1)," << endl
		<< "racine (option 2)," << endl
		<< "cube (option 3)." << endl
		<< "Entrez le numero d'option correspondant : ";
	cin >> option;

	if (option == '1') //structure de répétition avec les conditions dans les if
	{
		reponse = pow(nombre, 2);
	}
	else if (option == '2')
	{
		reponse = sqrt(nombre);
	}
	else if (option == '3')
	{
		reponse = pow(nombre, 3);
	}

	cout << "Resultat : " << reponse << endl;

	return 0;
}