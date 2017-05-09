#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream lecture("scientifique.txt");
	string nomUtilisateur;
	bool nomTrouve = false;

	string nom;
	bool nomTerminer;
	string dateNaissance;
	bool dateNaissanceTrouver;
	string dateDeces;
	bool dateDecesTrouver;
	string domaine;
	bool domaineTrouver;

	string ligne;


	do
	{

		nomUtilisateur = "";
		//Entrer d'un nom par l'utilisateur
		cout << "Entrer le nom d'un scientifique du 19e siecle (Q pour quitter le programme) : ";
		getline(cin, nomUtilisateur);

		//Fonction quitter
		if (nomUtilisateur != "Q")
		{
			while (lecture.peek() != EOF && !nomTrouve)
			{
				//Réinitialisation des variables
				nom = "";
				nomTerminer = false;
				dateNaissance = "";
				dateNaissanceTrouver = false;
				dateDeces = "";
				dateDecesTrouver = false;
				domaine = "";
				domaineTrouver = false;

				getline(lecture, ligne);

				//Obtention des informations du nom du fichier sur la ligne x
				for (int i = 1; i <= ligne.length() - 3; ++i)
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
				//Comparaison entre nom de l'utilisateur et sur la ligne x du fichier
				nomTrouve = nomUtilisateur == nom;
			} //fin du while


			if (nomTrouve)
			{
				cout << "Date de naissance : " << dateNaissance << endl;
				cout << "Date de deces : " << dateDeces << endl;
				cout << "Domaine et nationalite : " << domaine << endl;
			}
			else
			{
				int nouvelAgeNaissance;
				int nouvelAgeDeces;
				string nouveauDomaine;
				cout << "Ce nom ne figure pas sur la liste." << endl;
				cout << "Entrer sa date de naissance : ";
				cin >> nouvelAgeNaissance;
				cout << "Entrer sa date de deces : ";
				cin >> nouvelAgeDeces;
				cout << "Entrer son domaine et sa nationalite : ";
				cin >> nouveauDomaine;

				ofstream ecriture("scientifique.txt");
				ecriture << nomUtilisateur << ';' << nouvelAgeNaissance
					<< '-' << nouvelAgeDeces << ';' << nouveauDomaine;
				ecriture.close();
			}
		}//fin du if (nomUtilisateur != "Q")
	} while (nomUtilisateur != "Q");











	return 0;
}