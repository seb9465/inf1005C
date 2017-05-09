#include <iostream>
#include <string>
using namespace std;
int main()
{
//[
	int entier = 123;
	double reel = 45.6;
	char caractere = 'X';
	string chaine = "bonjour";
	
	cout << entier;
	cout << reel << caractere;
	cout << chaine;
	// Malgré qu'il y ait plusieurs lignes d'instructions dans le programme,
	// les affichages précédents seront sans espacement.
	
	cout << endl; // endl indique une fin de ligne (end of line).
	cout << entier << endl; 
	cout << reel << " " << caractere << endl;
	cout << chaine << endl;
	
	// Résultat:
	// 12345.6Xbonjour
	// 123
	// 45.6 X
	// bonjour
//]
}
