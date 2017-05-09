#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool creationFichierBinaire()
{
	ifstream lecture;
	fstream ecritureBinaire;
	double nombre;
	lecture.open("data.txt");
	// en lecture et écriture
	ecritureBinaire.open("data.bin", ios::binary | ios::out | ios::in);

	if (!lecture.fail() && !ecritureBinaire.fail())
	{
		while (!ws(lecture).eof())
		{
			lecture >> nombre;
			ecritureBinaire.write((char*)& nombre, sizeof(nombre));
		}
		lecture.close();

		double temp;
		ecritureBinaire.seekg(2 * sizeof(double), ios::beg);
		ecritureBinaire.read((char*)& temp, sizeof(double));
		cout << temp << endl;
		ecritureBinaire.close();
		return true;
	}
	else
		return false;

}

int main(void)
{
	if (creationFichierBinaire())
		cout << "creation reussie";
	else
		cout << "echec de creation";
	return 0;
}