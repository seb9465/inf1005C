/**
*  Validation d'une entrée.
*/
#include <iostream>
using namespace std; //[
int main()
{
	bool erreur = false;
	do {
		cout << "Entrer un entier: ";
		int entier;
		cin >> entier;
		if (cin.fail()) {
			erreur = true;
			cout << "Erreur fatale, cin est inutilisable" << endl;
			cin.clear();
			cin.ignore(80, '\n');
			cout << "cin est maintenant réinitialisé" << endl;
		}
		else {
			erreur = false;
			cout << entier << " lu correctement" << endl;
		}
	} while (erreur);
}
 
//]
// vim: ts=3