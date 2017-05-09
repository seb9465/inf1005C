#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
	int nombreADeviner = 0;
	int nombreATrouver = 0;
	bool nombreEstDeviner = false;

	srand(time(nullptr));
	nombreADeviner = rand() % 51;

	cout << "Entrez un nombre : ";
	cin >> nombreATrouver;

	while (!nombreEstDeviner)
	{
		if (nombreATrouver < nombreADeviner)
		{
			cout << "Nombre trop petit." << endl;
		}
		else
		{
			cout << "Nombre trop grand" << endl;
		}
		cout << "Entrez un nouveau nombre : ";
		cin >> nombreATrouver;
		nombreEstDeviner = nombreADeviner == nombreATrouver;
	}

	cout << "Bravo!! Vous avez trouve le nombre." << endl;


}