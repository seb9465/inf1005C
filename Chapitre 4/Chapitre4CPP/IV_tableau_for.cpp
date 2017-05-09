#include <iostream>
using namespace std;

int main()
{ //[
	// Accolades vides pour un tableau rempli de zéros:
	int liste1[3] = { };
	for (int i = 0; i < 3; i++)
		cout << liste1[i] << ' ';
	// Résultat: 0 0 0
	
	// Accolades avec valeurs pour spécifier le contenu:
	int liste2[3] = { 2, 7, 8 };
	for (int i = 0; i < 3; i++)
		cout << liste2[i] << ' ';
	// Résultat: 2 7 8
	
//]
}

// vim: ts=3