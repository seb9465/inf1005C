#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Personne
{
	char Nom[40];
	int Age;
};


void AjouterPersonne(fstream & Fichier)
{
	Personne UnePersonne;
	cout << "Nom ";
	cin >> UnePersonne.Nom;
	cout << "Age ";
	cin >> UnePersonne.Age;
	Fichier.seekp(0, ios::end);
	Fichier.write((char*)& UnePersonne, sizeof(UnePersonne));

}
void LectureFichier(fstream & Fichier)
{
	int NbElement;
	Personne UnePersonne;
	Fichier.seekp(0, ios::end);
	NbElement = Fichier.tellp() / sizeof(Personne);
	Fichier.seekp(0, ios::beg);
	for (int i = 0; i< NbElement; i++)
	{
		Fichier.read((char *)& UnePersonne, sizeof(UnePersonne));
		cout << UnePersonne.Nom << " " << UnePersonne.Age << endl;
	}

}

int main()
{

	fstream FichierPersonne;
	FichierPersonne.open("personne.bin", ios::binary | ios::in | ios::out);
	if (FichierPersonne.fail())
	{
		FichierPersonne.open("personne.bin", ios::binary | ios::in | ios::out | ios::trunc);
		if (FichierPersonne.fail())
			return 0;
		else
			cout << "Fichier existe" << endl;
	}
	else
	{
		cout << "FichierExiste" << endl;


		AjouterPersonne(FichierPersonne);

		AjouterPersonne(FichierPersonne);

		LectureFichier(FichierPersonne);
		FichierPersonne.close();

		return 0;
	}
