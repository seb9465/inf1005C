#include <iostream>
using namespace std;
//[
enum Sexe { F, M };

struct Adresse { // Définition d'un type Adresse étant un enregistrement
	int   numero;
	char  rue[31], ville[41], codePostal[7];
};

struct Membre {  // Définition d'un type Membre étant un enregistrement
	char          nom[51], prenom[51];
	unsigned char age;
	Sexe          sexe;
	Adresse       adresse;
	char          telephone[31];
	float         montantDu;
};
//]

void initialiserMembre(Membre& membre_out)
{
	Adresse adresse = { 2900, "Edouard-Montpetit", "Montreal", "H3T1J4" };
	Membre membre = { "Doe", "John", 18, M, adresse, "514-555-1234", 0.0 };
	membre_out = membre;
}

//[
int main()
{
	// Définition de variables de type Membre
	Membre etudiant, clubSocial[50];
//]
	initialiserMembre(etudiant);
	clubSocial[0] = etudiant;
	cout << clubSocial[0].prenom << ' ' << clubSocial[0].nom << endl;
}

