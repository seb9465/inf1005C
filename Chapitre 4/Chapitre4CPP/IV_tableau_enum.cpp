#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{ //[
	enum Departement { CIVIL, MECA , ELEC, 
	                   INFO, NBDEPARTEMENTS };
	enum Grade { BING, MSCA, PHD, NBGRADES };
	enum Sexe { FEMME, HOMME, NBSEXES };
	int gradues[NBDEPARTEMENTS][NBGRADES][NBSEXES];
	
//]
	// Mettre des valeurs aléatoires, juste pour tester...
	srand(unsigned(time(NULL)));
	for (int i = 0; i < NBDEPARTEMENTS; i++)
		for (int j = 0; j < NBGRADES; j++)
			for (int k = 0; k < NBSEXES; k++)
				gradues[i][j][k] = rand()%30;
//[
	int nbrePhdInformatique =
	        gradues[INFO][PHD][FEMME] +
	        gradues[INFO][PHD][HOMME];
	
//]
	// Afficher le résultat.
	cout << nbrePhdInformatique;
}

// vim: ts=3