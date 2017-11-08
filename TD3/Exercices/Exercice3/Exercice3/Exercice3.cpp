/**
* Suite de Fibonacci.
* \fichier   Exercice3.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   11 octobre 2014
* Créé le 9 octobre 2014
*/

#include < iostream>

using namespace std;

int main()
{
	int valeurN = 0;
	const int VALEUR_N_1 = 1,
		VALEUR_N_2 = 1;

	cout << "Entrez la valeur de n : ";
	cin >> valeurN;

	int nombre = VALEUR_N_2,
		ancienNombre = VALEUR_N_1;

	if (valeurN > 2)
	{
		for (int i = 2; i < valeurN; i++)
		{
			nombre += ancienNombre;
			ancienNombre = nombre - ancienNombre;
		}
		cout << " Resultat : " << nombre << endl;
	}
	else if (valeurN == 1)
	{
		cout << "Resultat : " << VALEUR_N_1 << endl;
	}
	else if (valeurN == 2)
	{
		cout << "Resultat : " << VALEUR_N_2 << endl;
	}

	return 0;
}