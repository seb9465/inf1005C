/**
*  Le type char.
**/
#include <iostream>
#include <cctype>  // Pour les fonctions isalpha, isdigit...
using namespace std;

int main()
{
//[
	cout << "Veuillez entrer un caractère: ";
	char lettre;
	cin >> lettre;
	
	//- Uniquement avec les opérations de base (pas besoin de "cctype") -
	if ((lettre >= 'a' && lettre <= 'z') || (lettre >= 'A' && lettre <= 'Z')) {
		cout << "Est un caractère alphabétique." << endl;
		cout << "Le code ASCII de la lettre est " << int(lettre) << endl;
		cout << "La lettre suivante est " << char(lettre + 1) << endl;
		if (lettre >= 'a' && lettre <= 'z')
			cout << "La lettre en majuscule est: " << char(lettre + ('A' - 'a')) 
			     << endl;
	}
	else if (lettre >= '0' && lettre <= '9')
		cout << "Est un chiffre." << endl;
	else
		cout << "N'est pas alphanumérique." << endl;

	//- En utilisant les fonctions de "cctype" (seulement les différences) -
	if (isalpha(lettre)) {
		// ...
		if (islower(lettre))
			cout << char(toupper(lettre));
	}
	else if (isdigit(lettre))
		cout << "Est un chiffre." << endl;
	else
		cout << "N'est pas alphanumérique." << endl;
//]
}

// vim: syn=cpp : ts=4 : wrap : lbr : bri : brishift=4 : tagmarker=//-,3,//TODO,m3,/**,M0,**/,M0 : colormarker=/*-,-*/,3 : foldseparator=-1