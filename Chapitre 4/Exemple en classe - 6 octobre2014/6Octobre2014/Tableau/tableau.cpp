#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	static const int DIMENSION = 10;
	int tableau[DIMENSION] = {};
	int valeurMaximale, valeurMinimale;

	srand(time(nullptr));

	cout << "Entrer une valeur maximale : ";
	cin >> valeurMaximale;

	cout << "Entrer une valeur minimale : ";
	cin >> valeurMinimale;

	for (int i = 0; i < DIMENSION; i++) {
		tableau[i] = rand() % (valeurMaximale - valeurMinimale + 1)
			+ valeurMinimale;
	}

	for (int i = 0; i < DIMENSION; i++) {
		cout << tableau[i] << endl;
	}

	int plusGrand = valeurMinimale - 1;
	int plusPetit = valeurMaximale + 1;
	for (int i = 0; i < DIMENSION; i++) {
		if (tableau[i] > plusGrand) {
			plusGrand = tableau[i];
		}
		if (tableau[i] < plusPetit) {
			plusPetit = tableau[i];
		}
	}

	cout << "La plus petite valeur est " << plusPetit << endl;
	cout << "La plus grande valeur est " << plusGrand << endl;

	return 0;
}