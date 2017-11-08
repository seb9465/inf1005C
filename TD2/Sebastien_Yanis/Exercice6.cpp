/*
* Nombre contenant un certain chiffre.
* \fichier   Exercice6.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   25 septembre 2014
* Cr�� le 24 septembre 2014
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Initialisation des variables
	int car0 = 0;
	int car1 = 0;
	int nombre = 0;
	int chiffre = 0;
	bool estBon = false;

	//Demande du nombre pour la comparaison
	cout << "Entrez un nombre entre 0 et 99 : " << endl;
	cin >> nombre;

	//V�rification du nombre respectant les bornes demand�es
	estBon = nombre >= 0 && nombre <= 99;

	cout <<"Intervalle respectee? " << boolalpha << estBon << endl;

	//D�cortication du nombre en 2 caract�res
	car0 = nombre / 10;
	car1 = nombre % 10;

	//Demande du chiffre � comparer
	cout << "Entrez un chiffre entre 1 et 9 : " << endl;
	cin >> chiffre;

	//Comparaison entre le nombre et le chiffre
	bool chiffreDansNb = car0 == chiffre || car1 == chiffre;

	//Affichage du r�sultat
	cout <<"Le nombre contient le chiffre? " << boolalpha << chiffreDansNb << endl;

	return 0;
}