#include <iostream>
#include <fstream>
using namespace std;

const int TAILLEMAX = 100;
struct Point
{
	float x, y;
};

struct Ligne
{
	Point p1, p2;
};
struct ListeLigne
{
	Ligne ensLigne[TAILLEMAX];
	int nombreLignes;
};

struct Cercle
{
	Point p;
	float rayon;
};
struct ListeCercle
{
	Cercle ensCercle[TAILLEMAX];
	int nombreCercles;
};
struct Image
{
	ListeCercle  tousCercles;
	ListeLigne tousLignes;
};


bool verifierExisteFichier(string nomFichier,
	ifstream  & lecture)
{

}
void lectureFichier(ifstream & lecture, Image & uneImage)
{
} 
void afficher(Image uneImage)
{

}
int main()
{
	Image paysage;

	return 0;
}