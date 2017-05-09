/**
* Gérer une liste de données dans un fichier.
* \fichier   Exercice6.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   11 octobre 2014
* Créé le 9 octobre 2014
*/

#include <iostream>
#include <fstream>
#include<string>

using namespace std;

int main()
{
	fstream lecture,
		ecriture;

	string nomUtilisateur,
		ligne,
		nom,
		dateNaissance,
		dateDeces,
		domaine;

	bool nomTerminer,
		dateNaissanceTrouver,
		dateDecesTrouver,
		domaineTrouver,
		nomTrouve = false;

	do//début while pour nomUtilisateur != "Q"
	{
		lecture.open("scientifique.txt", ios::in);

		cout << "Entrer le nom d'un scientifique du 19e siecle (Q pour quitter le programme) : ";	//Entrer d'un nom par l'utilisateur
		getline(cin, nomUtilisateur);

		nomTrouve = false;
		while (lecture.peek() != EOF && !nomTrouve &&nomUtilisateur != "Q")	//Lecture du fichier complet
		{
			getline(lecture, ligne);

			nom = ""; //Réinitialisation des variables
			nomTerminer = false;
			dateNaissance = "";
			dateNaissanceTrouver = false;
			dateDeces = "";
			dateDecesTrouver = false;
			domaine = "";
			domaineTrouver = false;
			for (int i = 1; i <= ligne.length() - 3; ++i) //Determination des informations caractere par caractere
			{
				if (!nomTerminer)
				{
					nomTerminer = ligne[i] == ';';
					nom += ligne[i - 1];
				}
				else if (!dateNaissanceTrouver)
				{
					dateNaissanceTrouver = ligne[i + 1] == '-';
					dateNaissance += ligne[i];
				}
				else if (!dateDecesTrouver)
				{
					dateDecesTrouver = ligne[i + 2] == ';';
					dateDeces += ligne[i + 1];
				}
				else if (!domaineTrouver)
				{
					domaineTrouver = ligne[i + 3] == ';';
					domaine += ligne[i + 2];
				}
			} //fin du for
			nomTrouve = nomUtilisateur == nom;
		}//fin while pour lire fichier
		lecture.close();

		if (nomTrouve)
		{
			cout << "Date de naissance : " << dateNaissance << endl;
			cout << "Date de deces : " << dateDeces << endl;
			cout << "Domaine et nationalite : " << domaine << endl;
		}
		else if (nomUtilisateur != "Q")
		{
			string nouvelDateNaissance,
				nouvelDateDeces,
				nouveauDomaine;
			cout << "Ce nom ne figure pas dans la liste du fichier." << endl;
			cout << "Entrer sa date de naissance : ";
			getline(cin, nouvelDateNaissance);
			cout << "Entrer sa date de deces : ";
			getline(cin, nouvelDateDeces);
			cout << "Entrer son domaine et sa nationalite : ";
			getline(cin, nouveauDomaine);

			ecriture.open("scientifique.txt", ios::app);
			ecriture <<endl << nomUtilisateur << ';'
				<< nouvelDateNaissance << '-'
				<< nouvelDateDeces << ';'
				<< nouveauDomaine;
			ecriture.close();

		}
	} while (nomUtilisateur != "Q");
	return 0;
}