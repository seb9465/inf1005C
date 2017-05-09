#include <iostream>
#include <string>
using namespace std;
int main()
{ //[
{
	int numero = 12345;
	string alliage = "aluminium";
	double enStock = 3.45e12;
	cout << numero << alliage << enStock;
}
// numero, alliage et enStock n'existent plus.
{
	cout << "Donner votre numéro de code";
	int numCode;
	cin  >> numCode;
	cout << numCode;
}
// numCode n'existe plus.
 
 
} //]
