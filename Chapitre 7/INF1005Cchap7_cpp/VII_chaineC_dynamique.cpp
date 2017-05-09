#include <iostream>
#include <cstring>
using namespace std;
int main()
{
//[
	char* ptrCar;             // Déclaration d'une chaîne de caractères dynamique.
	
	ptrCar = new char[37];             // Attribution d'espace pour 37 caractères.
	strcpy(ptrCar, "Premiere heure");  // Mémorisation d'une chaîne dans cet espace.
	cout << ptrCar;           // Affiche la chaîne.
	
	delete[] ptrCar;          // Remet en disponibilité l'espace mémoire.
	ptrCar = 0;
	
//]
}