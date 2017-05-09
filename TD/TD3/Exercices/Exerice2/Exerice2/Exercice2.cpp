/**
* Différentes opérations sur un nombre.
* \fichier   Exercice2.cpp
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
	char option = '1';

	cout << "Entrez un nombre : ";
	cin >> nombre;

	cout << "Choisir une option parmi les suivantes : " << endl
		<< "carree (option 1)," << endl
		<< "racine (option 2)," << endl
		<< "cube (option 3)." << endl
		<< "Entrez le numero d'option correspondant : ";
	cin >> option;

	switch (option)
	{
	case ('1') : reponse = pow(nombre, 2);
		break;
	case ('2') : reponse = sqrt(nombre);
		break;
	case ('3') : reponse = pow(nombre, 3);
		break;
	}

	cout << "Resultat : " << reponse << endl;

	return 0;
}