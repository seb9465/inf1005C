/**
*  Exemple de "while".
*/
#include <iostream>
using namespace std;

int main()
{
	//[
	char reponse = 'n';
	cout << "Voulez vous entrer un nombre ? (o/n) ";
	cin >> reponse;

	int somme = 0;
	while (reponse == 'o') {
		cout << "Entrer un nombre entier: ";
		int nombre;
		cin >> nombre;
		somme += nombre;

		cout << "Voulez vous entrer un autre nombre ? (o/n) ";
		cin >> reponse;
	}
	cout << "La somme est: " << somme << endl;

	//]
}


