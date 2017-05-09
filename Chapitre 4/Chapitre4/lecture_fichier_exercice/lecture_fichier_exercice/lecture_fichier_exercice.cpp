#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string nomFichier = "";
	ifstream lecture;

	cout << "Entrez le nom d'un fichier : ";
	cin >> nomFichier;
	lecture.open(nomFichier + ".txt");

	if (!lecture.fail())
	{
		while (!ws(lecture).eof())
		{
			int valeur;
			lecture >> valeur;
			cout << valeur << endl;
		}
		lecture.close();
	}
	else
	{
		cout << "Le fichier n'existe pas." << endl;
	}


	return 0;
}