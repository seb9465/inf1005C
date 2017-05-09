#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct rendezVous
{
	string description;
	int heure;
	int duree;
};

struct listeRDV
{
	rendezVous liste[24];
	int nombreRDVliste;
};

struct listeRDVDyna
{
	rendezVous * liste;
	int nombreRDVliste;
};

struct listeRDVElementDyna
{
	rendezVous * liste[24];
	int nombreRDVliste;
};

struct listeRDVTabElementDyna
{
	rendezVous ** liste;
	int nombreRDVliste;
	int capaciteListe;
};


int main()
{
	ifstream lecture("rdv.txt");
	if (!lecture.fail())
	{

		// allocation statique d'un tableau dont 
		// chaque elément est de type  rendezVous

		listeRDV lundi;
		lundi.nombreRDVliste = 0;
		while (!ws(lecture).eof())
		{
			
			lecture >> lundi.liste[lundi.nombreRDVliste].heure
				>> lundi.liste[lundi.nombreRDVliste].duree;
			getline(lecture, lundi.liste[lundi.nombreRDVliste].description);
			lundi.nombreRDVliste++;
		}

		lecture.clear();
		lecture.seekg(0, ios::beg);
		// allocation dynamique d'un tableau dont 
		// chaque elément est de type  rendezVous
		listeRDVDyna mardi;
		mardi.nombreRDVliste = 0;
		//   lire le fichier pour déterminer le nombre de
		//  rdv
		string rdv;
		while (!ws(lecture).eof())
		{
			mardi.nombreRDVliste++;
			getline(lecture, rdv);
		}
		lecture.clear(); // effacer le eof
		lecture.seekg(0, ios::beg);// se placer au debut du fichier
		// allocation dynamique
		mardi.liste = new  rendezVous[mardi.nombreRDVliste];
		// on relit le fichier
		for (int i = 0; i < mardi.nombreRDVliste; i++)
		{
			lecture >> mardi.liste[i].heure
				>> mardi.liste[i].duree;
			getline(lecture, mardi.liste[i].description);
		}


		lecture.clear(); // effacer le eof
		lecture.seekg(0, ios::beg);// se placer au debut du fichier
		// allocation statique d'un tableau dont 
		// chaque elément est de type dynamique de type rendezVous
		listeRDVElementDyna mercredi;
		mercredi.nombreRDVliste = 0;
		int heure, duree;
		string description;
		
		while (!ws(lecture).eof())
		{
			lecture >> heure >> duree;
			getline(lecture, description);
			mercredi.liste[mercredi.nombreRDVliste] = new rendezVous;
			mercredi.liste[mercredi.nombreRDVliste]->heure = heure;
			mercredi.liste[mercredi.nombreRDVliste]->duree = duree;
			mercredi.liste[mercredi.nombreRDVliste]->description = description;
			mercredi.nombreRDVliste++;
		}

		lecture.clear(); // effacer le eof
		lecture.seekg(0, ios::beg);// se placer au debut du fichier
		// allocation dynamique du tableau dont chaque
		// élément du tableau est de type 
		listeRDVTabElementDyna jeudi;
		jeudi.nombreRDVliste = 0;
		jeudi.capaciteListe = 10;
		jeudi.liste = new rendezVous *[jeudi.capaciteListe];
		int uneHeure, uneDuree;
		string uneDescription;
		bool termine = false;
		
		while (!ws(lecture).eof() && !termine)
		{
			lecture >> uneHeure >> uneDuree;
			getline(lecture, uneDescription);
			if (jeudi.nombreRDVliste < jeudi.capaciteListe)
			{
				jeudi.liste[jeudi.nombreRDVliste] = new rendezVous;
				jeudi.liste[jeudi.nombreRDVliste]->heure = uneHeure;
				jeudi.liste[jeudi.nombreRDVliste]->duree = uneDuree;
				jeudi.liste[jeudi.nombreRDVliste]->description = uneDescription;
				jeudi.nombreRDVliste++;
			}
			else
				termine = true;

		}
	}
	else
		cout << "impossible de lire le fichier" << endl;

	return 0;
}