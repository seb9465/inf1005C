#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Marchandise
{
	char  nom[50];
	int quantite;
};
// créer un fichier binaire s'il n'existe pas
bool ouvrirOuCreer(fstream& fichier, const string& nomFichier)
{
	static const bool ERREUR = false, REUSSI = true;
	fichier.close(); // Au cas où la variable "fichier" passée aurait un fichier déjà ouvert.
	//[
	//- Tentative d'ouvrir un fichier existant. -
	fichier.open(nomFichier, ios::binary | ios::in | ios::out);
	if (fichier.fail()) {
		//- Tentative d'ouvrir un nouveau fichier vide. -
		fichier.open(nomFichier, ios::binary | ios::in | ios::out | ios::trunc);
		if (fichier.fail())
			// En cas d'échec, on indique qu'il y a eu une erreur.
			return false;
		else
			return true;
		//NOTE: Normalement, cette fonction ne devrait pas afficher;
		// ici fait pour montrer quelle condition est exécutée.
	}
	else
		return true;

	// Le fichier est bien ouvert en lecture/écriture...
	//]
	return true;
}
// fonction qui demande à l'usager les infos sur la marchandise
void demanderInfos(Marchandise & unemarchandise){
	cout << "Donner le nom de la marchandise: ";
	cin >> unemarchandise.nom;
	cout << "Donner la quantite: ";
	cin >> unemarchandise.quantite;
}

// ajouter une marchandises dans le fichier binaire
void ajouterUneMarchandise(fstream & fichier, Marchandise  unemarchandise)
{
	fichier.seekp(0, ios::end);
	fichier.write((char *)& unemarchandise, sizeof(unemarchandise));

}
//  lire le contenu du contenu du fichier binaire
void afficherContenu(fstream & fichier)
{
	Marchandise unemarchandise;
	int nombreElement = 0;
	fichier.seekg(0, ios::end);
	nombreElement = fichier.tellg() / sizeof(Marchandise);
	//	cout << fichier.tellg();
	fichier.seekg(0, ios::beg);
	for (int i = 0; i < nombreElement; i++)
	{
		fichier.read((char*)& unemarchandise, sizeof(unemarchandise));
		cout << unemarchandise.nom << "\t" << unemarchandise.quantite << endl;
	}

}
// modifier la quantité d'une marchandise
bool modifierQuantite(fstream & fichier)
{
	bool trouve = false;
	Marchandise unemarchandise;
	demanderInfos(unemarchandise);
	Marchandise marchandiseAncien;
	int nombreElement = 0;
	fichier.seekg(0, ios::end);
	nombreElement = fichier.tellg() / sizeof(Marchandise);
	//	cout << fichier.tellg();
	fichier.seekg(0, ios::beg);
	for (int i = 0; i < nombreElement && !trouve; i++)
	{
		fichier.read((char*)& marchandiseAncien, sizeof(marchandiseAncien));
		if (string(marchandiseAncien.nom) ==
			string(unemarchandise.nom))
		{
			fichier.seekg(-1 * streamoff(sizeof(Marchandise)),
				ios::cur);
			fichier.write((char*)& unemarchandise, sizeof(unemarchandise));
			trouve = true;
		}
	}
	return trouve;
}

int main()
{
	string nomFichier;
	fstream fichier;
	Marchandise uneMarchandise;
	cout << " donner le nom du fichier ";
	cin >> nomFichier;
	if (ouvrirOuCreer(fichier, nomFichier))
	{
		afficherContenu(fichier);
		// on ajoute 2 marchandises
		demanderInfos(uneMarchandise);
		ajouterUneMarchandise(fichier, uneMarchandise);
		demanderInfos(uneMarchandise);
		ajouterUneMarchandise(fichier, uneMarchandise);
		// on affiche le contenu
		afficherContenu(fichier);
		if (modifierQuantite(fichier))
		{
			cout << " mise  a jour reussi" << endl;
			afficherContenu(fichier);
		}
		else
			cout << " marchandise non trouvée" << endl;

	}


	return 0;
}
