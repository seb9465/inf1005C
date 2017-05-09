#include <iostream>
#include <string>
using namespace std;
//[
int main()
{
	int     index    = -23;
	double  distance = 12.345;
	char    lettre   = 'X';
	string  nom      = "Jeremi Desir";
	bool    vrai     = true;

	cout << "La valeur de Index est "    << index    << endl;
	cout << "La valeur de Distance est " << distance << endl;
	cout << "La valeur de Lettre est "   << lettre   << endl;
	cout << "La valeur de Nom est "      << nom      << endl;

	index = 31;
	cout << "La valeur decimale/octale/hexadecimale de Index est "
	     << dec << index << '/' << oct << index << '/' << hex << index << endl;
	cout << "La valeur hexadecimale de Lettre est " << (unsigned)lettre << endl;
	cout << "vrai est " << vrai << " ou " << boolalpha << vrai << endl;

	cout << "Donner une valeur decimale --> ";
	cin  >> index;
	cout << "La valeur lue en hexadecimal est " << index << endl;
	
	cout << "Entrez des espaces suivis de deux caracteres, le deuxieme pouvant etre un espace --> ";
	char car1, car2;
	cin >> car1 >> noskipws >> car2;
	cout << "Les deux caracteres lus sont '" << car1 << "' et '" << car2 << "'" << endl;
}
 
 
//]