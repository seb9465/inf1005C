#include<string>
#include<iostream>
#include<fstream>

using namespace std;

struct personne
{
	string nom;
	int age;
};
struct slistepersonne
{
	personne** liste;
	int nombrePersonne;
};

bool verifierExistenceLecture(string nomFichier, ifstream &lecture)
{
	lecture.open(nomFichier);
	return (!lecture.fail());
}
bool verifierExistenceEcriture(string nomFichier, ofstream &ecriture)
{
	ecriture.open(nomFichier);
	return (!ecriture.fail());
}
// lire le fichier une première fois pour en déterminer le
// nombre de personnes
int determinerNombre(ifstream &lecture)
{
	string  ligne;
	int nbElements = 0;
	while (!ws(lecture).eof())
	{
		getline(lecture, ligne);
		nbElements++;
	}
	lecture.clear();
	lecture.seekg(0, ios::beg);
	return nbElements;
}
//allouer l'espace et relire le fichier
void stockerInfo(ifstream &lecture, 
	             slistepersonne &tous)
{
	tous.liste = new personne* [tous.nombrePersonne];
	personne * unePersonne;
	for (int i = 0; i < tous.nombrePersonne; i++)
	{
		unePersonne = new personne;
		lecture >> (*unePersonne).nom 
			    >> unePersonne->age;
		tous.liste[i] = unePersonne;
	}
}
// demander les infos d'une personne
//  et allouer l'espace nécessaire
personne* demanderInfos()
{
	personne *  unePersonne = new personne;
	cout << " Nom ";
	cin >> unePersonne->nom;
	cout << " age ";
	cin >> unePersonne->age;
	return  unePersonne;
}
// ajouter  le pointeur nouvPersonne dans le tableau
void ajouterInfos(slistepersonne &tous, 
	personne * nouvPersonne)
{
	personne ** nouvListe = 
		new personne *[tous.nombrePersonne + 1];
	for (int i = 0; i < tous.nombrePersonne; i++)
		nouvListe[i] = tous.liste[i];
	
	nouvListe[tous.nombrePersonne] = nouvPersonne;
	delete[] tous.liste;
	tous.liste = nouvListe;
	tous.nombrePersonne++;
}
// sauver les infos de la structure slistepersonne
// dans un fichier
void sauverInfo(slistepersonne tous, ofstream & ecriture)
{
	for (int i = 0; i < tous.nombrePersonne; i++)
		ecriture << tous.liste[i]->nom << "\t"
		<< tous.liste[i]->age << endl;
}
void afficher(slistepersonne tous)
{
	for (int i = 0; i < tous.nombrePersonne; i++)
	{
		cout << tous.liste[i]->nom << "\t"
			<< tous.liste[i]->age << endl;
	}
}
int main()
{
	ifstream lecture;
	string nomFichier;
	slistepersonne ensPersonne;
	ofstream ecriture;
	cout << " Veuillez entrer le nom du fichier de donnees: ";
	cin >> nomFichier;

	if (verifierExistenceLecture(nomFichier, lecture))
	{
		ensPersonne.nombrePersonne = determinerNombre(lecture);
	}
	stockerInfo(lecture, ensPersonne);
	// tant que l'usager ne veut pas terminer
	// demander les infos d'un structurePersonne 
	// et l'ajouter  à la structure ensPersonne
	bool terminer = false;
	char reponse;
	do
	{

		cout << " voulez vous quitter le programme";
		cin >> reponse;
		terminer = (reponse == 'o' ? true: false);
		// terminer = (reponse == 'o');
		if (!terminer)
		{
			personne * nouveau = demanderInfos();
			ajouterInfos(ensPersonne, nouveau);
		}
	}
	while (!terminer);
	afficher(ensPersonne);
	cout << " Veuillez entrer le nom du fichier pour sauver les infos: ";
	cin >> nomFichier;
	// sauver les infos dans  un fichier
	if (verifierExistenceEcriture(nomFichier, ecriture))
	{
		sauverInfo(ensPersonne, ecriture);
	}
	return 0;
}