#include <iostream>
#include <iomanip>
using namespace std;
//[
// Ordre d'ex�cution:
void afficherNombresImpairs()             //
{                                         //
	for (int i = 11; i < 30; i += 2)      // 4
		cout << setw(4) << i;             // 5 (cette ligne est ex�cut�e 10 fois)
}                                         // 6 La fin de la fonction est atteinte ->
//   retourne o� la fonction � �t� appel�e.
//
int main()                                // <- D�but de l'ex�cution
{                                         //
	cout << "Nombres impairs de 10 � 30"; // 1
	cout << endl << endl;                 // 2
	afficherNombresImpairs();             // 3 -> Va ex�cuter la fonction.
	cout << endl << endl;                 // 7
	cout << "Affichage termin�";          // 8
}                                         // 9 -> La fin du programme est atteinte. Il est possible de retourner un code d'erreur au programme qui a appel� notre programme; par d�faut le code est z�ro, signifiant "pas d'erreur".

//]
// vim: ts=4