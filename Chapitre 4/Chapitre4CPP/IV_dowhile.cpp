/**
*  Exemple de "do while".
*/
#include <iostream>
using namespace std;

int main()
{
 //[
	char reponse = 'n';
	
	int somme = 0;
	do {
		cout << "Entrer un nombre entier: ";
		int nombre;
		cin >> nombre;
		somme += nombre;
		
		cout << "Voulez vous entrer un autre nombre ? (o/n) ";
		cin >> reponse;
	} while (reponse == 'o');
	cout << "La somme est: " << somme << endl;
	
//]
}
 
 
