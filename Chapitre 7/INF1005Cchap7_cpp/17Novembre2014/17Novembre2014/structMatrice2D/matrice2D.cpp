#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
struct typeMatrice
{
	int nbLignes, nbColonnes;
	int** tableau;
};

// allouer l'espace mémoire selon le nombde de lignes et colonnes
void  alloue2D(typeMatrice  & uneMatrice)
{
	uneMatrice.tableau = new int *[uneMatrice.nbLignes];
	for (int i = 0; i < uneMatrice.nbLignes; i++)
		uneMatrice.tableau[i] = new int[uneMatrice.nbColonnes];
}
// détruire l'espace mémoire
void detruire2d(typeMatrice uneMatrice)
{
	for (int i = 0; i < uneMatrice.nbLignes; i++)
		delete[] uneMatrice.tableau[i];
	delete[] uneMatrice.tableau;
	uneMatrice.tableau = 0;
}
// afficher le contenu de la matrice
void afficher(typeMatrice uneMatrice)
{
	
	for (int i = 0; i < uneMatrice.nbLignes; i++)
	{
		for (int j = 0; j < uneMatrice.nbColonnes; j++)
			cout << uneMatrice.tableau[i][j] << "\t";
		cout << endl;
	}
}
// mettre des valeurs aléatoires dans la matrice netre [min , max]
void mettreContenu(typeMatrice & uneMatrice, int min, int max)
{
	srand(time(nullptr));
	for (int i = 0; i < uneMatrice.nbLignes; i++)
	{
		for (int j = 0; j < uneMatrice.nbColonnes; j++)
			uneMatrice.tableau[i][j] = rand() % (max - min) + min;	
	} 
}

void main()
{
	typeMatrice laMatrice;

	cout << " nombre de lignes  et nombre de colonnes ";
	cin >> laMatrice.nbLignes >> laMatrice.nbColonnes;
	alloue2D(laMatrice);
	mettreContenu(laMatrice, 10, 50);
	afficher(laMatrice);
	detruire2d(laMatrice);
}
