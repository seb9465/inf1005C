#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool lectureFichierBinaire(int & nombreElement)
{
	ifstream lecture;
	double nombre;


	lecture.open("data.bin", ios::binary);

	if (!lecture.fail())
	{
		lecture.seekg(0, ios::end);
		nombreElement = lecture.tellg() / sizeof(double);


		lecture.close();
		return true;
	}
	else
		return false;
}

int main(void)
{
	int nombreElements;
	if (lectureFichierBinaire(nombreElements))
	{
		cout << "lecture reussie" << endl;
		cout << nombreElements << " elements dans le fichier" << "\n";
	}
	else
		cout << " echec de creation";

	return 0;
}