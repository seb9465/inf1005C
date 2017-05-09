#include <iostream>
#include <iomanip>
using namespace std;

void modifier(int entier1, int& entier2)
{
	entier1 = entier1 + 100;
	entier2 = entier2 + 100;
	cout << "(2) Les valeurs sont ";
	cout << setw(4) << entier1 << setw(4) << entier2 << endl;
}

int main()
{
	int compteur = 7, indice = 12;

	cout << "(1) Les valeurs sont ";
	cout << setw(4) << compteur << setw(4) << indice << endl;

	modifier(compteur, indice);

	cout << "(3) Les valeurs sont ";
	cout << setw(4) << compteur << setw(4) << indice << endl;
}
