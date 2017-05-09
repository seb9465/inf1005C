#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//[
struct Etudiant {
	char nom[50], prenom[50];
	int matricule;
};

void convertirFichierTexteEnBinaire(
	const string& nomFichierTexte,
	const string& nomFichierBinaire)
{
	ifstream entree(nomFichierTexte);
	ofstream sortie(nomFichierBinaire, ios::binary);

	if (!entree.fail() && !sortie.fail()) {
		while (!ws(entree).eof()) {
			Etudiant unEtudiant;
			//- Lire du fichier texte. -
			entree >> unEtudiant.prenom >> unEtudiant.nom >> unEtudiant.matricule;
			//- Écrire dans le fichier binaire. -
			sortie.write((char*)&unEtudiant, sizeof(unEtudiant));
		}
	}
}
//]

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
			return ERREUR;
		else
			cout << "(Nouveau fichier créé.)" << endl;
			//NOTE: Normalement, cette fonction ne devrait pas afficher;
			// ici fait pour montrer quelle condition est exécutée.
	}
	else
		cout << "(Fichier existant ouvert.)" << endl;
	
	// Le fichier est bien ouvert en lecture/écriture...
//]
	return REUSSI;
}

//[
unsigned tailleDuFichier(istream& fichier)
{
	streampos anciennePosition = fichier.tellg(); // Conserve la position de la tête.
	fichier.seekg(0, ios::end);                   // Place la tête à la fin du fichier.
	unsigned taille = unsigned(fichier.tellg());  // La taille = position de la tête.
	fichier.seekg(anciennePosition);              // Replace la tête où elle était.
	return taille;
}

void lireFichierBinaire(istream& fichier)
{
	unsigned nElements = tailleDuFichier(fichier) / sizeof(Etudiant);
	for (unsigned i = 0; i < nElements; i++) {
		Etudiant etudiant;
		fichier.read((char*)&etudiant, sizeof(etudiant));
		cout << etudiant.nom << ' ' << etudiant.prenom << ' '
		     << etudiant.matricule << endl;
	}
}
//]

istream& viderFlot(istream& flot)
{
	flot.ignore((flot.rdbuf())->in_avail());
	return flot;
}

//[
void ajouterEtudiant(ostream& fichier, const Etudiant& etudiant)
{
	fichier.seekp(0, ios::end); // Placer la tête à la fin du fichier.
	fichier.write((char*)&etudiant, sizeof(etudiant));
}

Etudiant demanderDonneesEtudiant()
{
	Etudiant etudiant;
	cout << "Nom: ";
	cin.getline(etudiant.nom, sizeof(etudiant.nom)-1);
	cout << "Prénom: ";
	cin.getline(etudiant.prenom, sizeof(etudiant.prenom)-1);
	cout << "Matricule: ";
	cin >> etudiant.matricule >> viderFlot;
	return etudiant;
}

void ajouterNouvelleEntreeDansFichier(ostream& fichier)
{
	Etudiant etudiant = demanderDonneesEtudiant();
	ajouterEtudiant(fichier, etudiant);
}
//]

void creerFichierBinaire()
{
	convertirFichierTexteEnBinaire("VI_etudiants.txt", "VI_etudiants.bin");
}

void afficherFichierBinaire()
{
	string nomFichier = "VI_etudiants.bin";
	fstream fichier;
	if (!ouvrirOuCreer(fichier, nomFichier))
		cout << "Impossible d'ouvrir " << nomFichier << endl;
	else
		lireFichierBinaire(fichier);
}

void ajouterNouvelleEntree()
{
	string nomFichier = "VI_etudiants.bin";
	fstream fichier;
	ouvrirOuCreer(fichier, nomFichier);
	ajouterNouvelleEntreeDansFichier(fichier);
}

int main()
{
	cout << endl << "Le fichier contenait:" << endl;
	afficherFichierBinaire();
	creerFichierBinaire();
	cout << endl << "Après la conversion du fichier texte en binaire:" << endl;
	afficherFichierBinaire();
	ajouterNouvelleEntree();
	cout << endl << "Après l'ajout de l'entrée:" << endl;
	afficherFichierBinaire();
}

// vim: syn=cpp : tagmarker=//-,3,//TODO,m3,/**,M0,**/,M0