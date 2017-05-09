#include <iostream>
#include <string>
using namespace std;

enum type_format{ PORTABLE, DESKTOP };
enum type_memoire{ KILO, MEGA, GIGA, TERRA };

struct type_compagnie
{
	string nom;
	string addresse;
	string URL;

};

struct type_ordinateur
{
	type_format format;
	type_compagnie compagnie;
	float tailleEcran;
	float cpu;
	int RAM;
	type_memoire memoireRAM;
	int disqueDur;
	type_memoire memoireDisque;

};

void main()
{
	type_ordinateur Amelie;
	Amelie.compagnie.nom = "lenovo";
	Amelie.disqueDur = 160;
	Amelie.memoireDisque = GIGA;

}