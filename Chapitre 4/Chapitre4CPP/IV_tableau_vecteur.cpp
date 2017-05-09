/**
*  Traitement des éléments d'un tableau.
*/
#include <iostream>
#include <cmath>    // Pour pow et sqrt.
using namespace std;
int main()
{
//[
	double vecteurA[10], vecteurB[10];
	
	//- Initialisation du vecteur -
	for (int i = 0; i < 10; i++)
		vecteurA[i] = 1.0;
	
	
	//- Affectation d'un tableau à un autre -
	for (int i = 0; i < 10; i++)
		vecteurB[i] = vecteurA[i];
	
//]
//[
	//- Comparaison de deux tableaux -
	bool estPareil = true;
	for (int i = 0; i < 10 && estPareil; i++)
		if (vecteurA[i] != vecteurB[i])
			estPareil = false;
	
	
	//- Calculer la norme d'un vecteur -
	double norme = 0.0;
	for (int i = 0; i < 10; i++)
		norme += pow(vecteurA[i], 2);
	norme = sqrt(norme);
	
//]
	cout << "estPareil=" << boolalpha << estPareil << ", norme=" << norme << endl;
}

// vim: syn=cpp : ts=3 : wrap : lbr : bri : brishift=3 : tagmarker=//-,3 : foldseparator=-1