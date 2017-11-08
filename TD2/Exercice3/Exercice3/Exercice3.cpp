/**
* Manipulation de chaines de caracteres.
* \fichier   Exercice3.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   25 septembre 2014
* Créé le 24 septembre 2014
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Initialisation des variables
	const string CHAINE_UN = "Bonjour ";
	const string CHAINE_DEUX = ", bienvenue au cours ";
	const string CHAINE_TROIS = " de Poly.";

	string prenom = "";
	string sigle = "";

	string chaineFinale = "";

	//Entrer du prénom et du sigle du cours
	cout << "Entrez votre prenom : ";
	cin >> prenom;

	cout << "Entrez le sigle du cours : ";
	cin >> sigle;

	//Calcul de la chaine finale
	chaineFinale = CHAINE_UN + prenom + CHAINE_DEUX + sigle + CHAINE_TROIS;

	//Afficher chaine finale
	cout << chaineFinale << endl;

	return 0;
}