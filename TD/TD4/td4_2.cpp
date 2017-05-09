#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Les constantes:
static const int DIMENSION = 7;
static const int BORDURE = 1;
static const int N_AGENTS = 10;
static const int N_TYPES = 3;
static const int N_MAXIMUM_ROUNDS = 100;

void test_tout(),
afficherGrille(int tableau[][DIMENSION]),
initialiserGrille(int tableau[][DIMENSION]),
peuplerGrille(int tableau[][DIMENSION], int type),
determineVoisinage(const int tableau[][DIMENSION], int voisins[], int x, int y),
deplacerAgent(int tableau[][DIMENSION], int agentsDejaBouges[][DIMENSION], int x, int y);
bool estSatisfait(int tableau[][DIMENSION], int x, int y, int seuil);

void test_tout() {
	int grille[DIMENSION][DIMENSION] = {},
		coordonneeX = 0,
		coordonneeY = 0,
		seuil = 0,
		agentsDejaBouges[DIMENSION][DIMENSION] = {};

	initialiserGrille(grille);

	afficherGrille(grille);

	cout << "Donner les coordonnees x d'une case : ";
	cin >> coordonneeX;
	cout << "Donner les coordonnees y d'une case : ";
	cin >> coordonneeY;

	int voisins[3] = {};
	for (int i = 0; i < 3; i++){
		voisins[i] = 0;
	}

	determineVoisinage(grille, voisins, coordonneeX, coordonneeY);

	cout << "\t VOISINAGE" << endl
		<< "Nombre de cellules vides : \t" << voisins[0] << endl
		<< "Nombre d'agents de type 1 : \t" << voisins[1] << endl
		<< "Nombre d'agents de type 2 : \t" << voisins[2] << endl;

	cout << "Entrer un seuil : ";
	cin >> seuil;

	bool estSatisf = estSatisfait(grille, coordonneeX, coordonneeY, seuil);
	cout << "\t EST SATISFAIT ?" << endl
		<< boolalpha << estSatisf << endl;

	for (int i = 0; i < DIMENSION; i++){
		for (int j = 0; j < DIMENSION; j++){
			agentsDejaBouges[i][j] = 0;
		}
	}

	deplacerAgent(grille, agentsDejaBouges, coordonneeX, coordonneeY);

	cout << "\t GRILLE" << endl;
	afficherGrille(grille);
	cout << "\t AGENTS_DEJA_BOUGES" << endl;
	afficherGrille(agentsDejaBouges);
}

void initialiserGrille(int tableau[][DIMENSION]) {
	for (int i = 0; i < DIMENSION; i++)
	{
		for (int j = 0; j < DIMENSION; j++)
		{
			tableau[i][j] = 0;
		}
	}

	int type = 1;
	peuplerGrille(tableau, type);
	type = 2;
	peuplerGrille(tableau, type);
}

void peuplerGrille(int tableau[][DIMENSION], int type) {
	int ligneAleatoire = 0,
		colonneAleatoire = 0;

	for (int cpt = 0; cpt < N_AGENTS; cpt++){
		bool estBon = false;
		while (!estBon){
			ligneAleatoire = (int)rand() % 5 + BORDURE;
			colonneAleatoire = (int)rand() % 5 + BORDURE;
			estBon = tableau[ligneAleatoire][colonneAleatoire] == 0;
		}
		tableau[ligneAleatoire][colonneAleatoire] = type;
	}
}

void afficherGrille(int tableau[][DIMENSION]) { //TODO: Mettre les bons types de paramètres.
	//TODO: Afficher tous les éléments de la grille.
	cout << setw(4);
	for (int i = BORDURE; i < DIMENSION - BORDURE; i++)
	{
		for (int j = BORDURE; j < DIMENSION - BORDURE; j++)
		{
			cout << tableau[i][j] << setw(4);
		}
		cout << endl;
	}
	// Attention au format de sortie : il faut afficher une matrice DIMENSION x DIMENSION correctement en lignes et colonnes.
}

void determineVoisinage(const int tableau[][DIMENSION], int voisins[], int x, int y) {
	voisins[0] = 0;
	voisins[1] = 0;
	voisins[2] = 0;

	for (int i = x - 1; i <= x + 1; i++){
		for (int j = y - 1; j <= y + 1; j++){
			if (tableau[i][j] == 0){
				voisins[0]++;
			}
			else if (tableau[i][j] == 1){
				voisins[1]++;
			}
			else if (tableau[i][j] == 2){
				voisins[2]++;
			}
			else;
		}
	}

	if (tableau[x][y] == 0){
		voisins[0]--;
	}
	else if (tableau[x][y] == 1){
		voisins[1]--;
	}
	else if (tableau[x][y] == 2){
		voisins[2]--;
	}
	else;
}

bool estSatisfait(int tableau[][DIMENSION], int x, int y, int seuil) {
	int voisins[N_TYPES] = {},
		tauxSatisfaction = 0,
		somme = 0;

	determineVoisinage(tableau, voisins, x, y);

	somme = voisins[1] + voisins[2];

	if (tableau[x][y] == 1 && somme != 0){
		tauxSatisfaction = voisins[1] / somme * 100;
	}
	else if (tableau[x][y] == 2 && somme != 0){
		tauxSatisfaction = voisins[2] / somme * 100;
	}
	else;

	return (tauxSatisfaction >= seuil);
}

void deplacerAgent(int tableau[][DIMENSION], int agentsDejaBouges[][DIMENSION], int x, int y) {
	bool estBon = false;
	int i = 0,
		j = 0;

	while (!estBon){
		i = (int)rand() % 5 + BORDURE;
		j = (int)rand() % 5 + BORDURE;

		estBon = tableau[i][j] == 0;
	}

	tableau[i][j] = tableau[x][y];
	tableau[x][y] = 0;

	agentsDejaBouges[i][j] = 1;
}

int nouveauRound(int grille[][DIMENSION], int seuil) {
	int agentsDejaBouges[DIMENSION][DIMENSION] = {},
		compteurDeplacement = 0;
	for (int i = 0; i < DIMENSION; i++){
		for (int j = 0; j < DIMENSION; j++){
			agentsDejaBouges[i][j] = 0;
		}
	}

	for (int i = BORDURE; i < DIMENSION - BORDURE; i++){
		for (int j = BORDURE; j < DIMENSION - BORDURE; j++){
			if (grille[i][j] != 0 && agentsDejaBouges[i][j] == 0 && !estSatisfait(grille, i, j, seuil)){
				deplacerAgent(grille, agentsDejaBouges, i, j);
				compteurDeplacement++;
			}
		}
	}

	return compteurDeplacement;
}

void initialiserGenerateurAleatoire() {
	srand(unsigned(time(nullptr)));
	rand();
}

int main() {
	initialiserGenerateurAleatoire();

	int grille[DIMENSION][DIMENSION] = {},
		seuil = 0,
		compteur = 0,
		nbDeplacements = 0;

	initialiserGrille(grille);

	cout << "\t GRILLE INITIALE" << endl;
	afficherGrille(grille);

	cout << "Donner le seuil : ";
	cin >> seuil;

	do{
		nbDeplacements = nouveauRound(grille, seuil);
		compteur++;
		cout << "round : " << compteur << "\t nombre deplacement : " << nbDeplacements << endl;
	} while (compteur < N_MAXIMUM_ROUNDS);

	cout << "\t GRILLE FINALE" << endl;
	afficherGrille(grille);
	cout << "Nombre de rounds faits : \t" << compteur << endl;
	cout << "Nomde d'agents deplaces au dernier round : \t" << nbDeplacements << endl;

	return 0;
}