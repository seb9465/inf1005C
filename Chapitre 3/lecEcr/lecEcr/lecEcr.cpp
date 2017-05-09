#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string nomfichier;
	cout << "Veiller donner le nom du fichier";
	cin >> nomfichier;

	ofstream creationFichier;
	creationFichier.open(nomfichier + ".txt");
}