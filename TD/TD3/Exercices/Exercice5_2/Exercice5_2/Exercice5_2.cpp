/**
* Méthode de Newton-Raphson.
* \fichier   Exercice5.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   11 octobre 2014
* Créé le 9 octobre 2014
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

	double valeura = 0.0,
		valeurInitiale = 0.0,
		precision = 0.0,
		ancienneValeur = 0.0,
		valeur = 0.0;

	cout << "Entrez la valeur de A : ";
	cin >> valeura;
	cout << "Entrez la valeur de precision : ";
	cin >> precision;

	valeurInitiale = valeura / 2;

	valeur = valeurInitiale;
	ancienneValeur = valeura;

	while ((abs(valeur - ancienneValeur) / ancienneValeur) > precision)
	{
		ancienneValeur = valeur;
		valeur = ((ancienneValeur + (valeura / ancienneValeur)) / 2);
	}

	cout << "La racine carree de " << valeura << " est " << valeur << " avec une precision de " << precision << endl;

	return 0;
}