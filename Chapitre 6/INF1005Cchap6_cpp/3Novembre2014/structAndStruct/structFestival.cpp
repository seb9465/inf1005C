#include <string>
using namespace std;
enum enuStyle {pop, jazz, alternative, rock,folk, metal};
struct Date
{
	int annee, mois, jour;
};
struct Adresse
{
	int numero;
	string rue;
	string codePostal;
};

struct Artiste
{
	string nom;
	enuStyle style;
};
struct Scene
{
	Adresse  adresse;
	string commanditaire;
};
struct Evenemnent
{
	Scene uneScene;
	Artiste unArtiste;
	Date uneDate;
};
const int MAXEV = 200;
struct Programmation
{
	Evenemnent listeEv[MAXEV];
	int nombreEvenement;
};
struct Festival
{
	string nom;
	Date debut, fin;
	Programmation TousProgrammes;
};
int main()
{
	Festival Francofolies;
}