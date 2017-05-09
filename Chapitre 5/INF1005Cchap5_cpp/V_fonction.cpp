#include <iostream>
#include <iomanip>
using namespace std;
//[
                                          // Ordre d'exécution:
void afficherNombresImpairs()             //
{                                         //
	for (int i = 11; i < 30; i += 2)      // 4
		cout << setw(4) << i;             // 5 (cette ligne est exécutée 10 fois)
}                                         // 6 La fin de la fonction est atteinte ->
                                          //   retourne où la fonction à été appelée.
                                          //
int main()                                // <- Début de l'exécution
{                                         //
	cout << "Nombres impairs de 10 à 30"; // 1
	cout << endl << endl;                 // 2
	afficherNombresImpairs();             // 3 -> Va exécuter la fonction.
	cout << endl << endl;                 // 7
	cout << "Affichage terminé";          // 8
}                                         // 9 -> La fin du programme est atteinte. Il est possible de retourner un code d'erreur au programme qui a appelé notre programme; par défaut le code est zéro, signifiant "pas d'erreur".

//]
// vim: ts=4