#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream lecture;
	string nomFichierLecture;
	string phrase;

	cout << "Donner le nom du fichier de lecture: ";
	cin >> nomFichierLecture;

	lecture.open(nomFichierLecture);
	if (!lecture.fail())
	{

		getline(lecture, phrase);
		getline(lecture, phrase);
		getline(lecture, phrase);

		ofstream ecriture("phrase3.txt");
		ecriture << phrase;
		ecriture.close();

		cout << phrase << endl;
	}
	else
	{
		cout << "Le fichier n'existe pas." << endl;
	}



	return 0;
}