#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()

using namespace std;

int main()
{
	static const int DIMENSION_1 = 10;
	static const int DIMENSION_2 = 5;
	int tableau[DIMENSION_1][DIMENSION_2] = {};
	int valeurMaximale, valeurMinimale;

	srand(time(nullptr));

	cout << "Entrer une valeur maximale : ";
	cin >> valeurMaximale;

	cout << "Entrer une valeur minimale : ";
	cin >> valeurMinimale;

	for (int i = 0; i < DIMENSION_1; i++) {
		for (int j = 0; j < DIMENSION_2; j++) {
			tableau[i][j] = rand() % (valeurMaximale - valeurMinimale + 1)
				+ valeurMinimale;
		}
	}

	for (int i = 0; i < DIMENSION_1; i++) {
		for (int j = 0; j < DIMENSION_2; j++) {
			cout << tableau[i][j] << "\t";
		}
		cout << endl;
	}

	cout << tableau << endl;
	/*int plusGrand = valeurMinimale - 1;
	int plusPetit = valeurMaximale + 1;
	for (int i = 0; i < DIMENSION; i++) {
		if (tableau[i] > plusGrand) {
			plusGrand = tableau[i];
		}
		if (tableau[i] < plusPetit) {
			plusPetit = tableau[i];
		}
	}*/

	/*cout << "la plus petite valeur est " << pluspetit << endl;
	cout << "la plus grande valeur est " << plusgrand << endl;*/

	return 0;
}