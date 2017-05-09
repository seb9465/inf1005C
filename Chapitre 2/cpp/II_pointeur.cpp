/**
*  Le type pointeur.
*/
#include <iostream>
using namespace std;
//[
int main()
{
	int     ageAlex = 7, ageSandie = 27;
	double  x = 1.2345, y = 32.14;

	int* ptrEntier;
	ptrEntier = &ageAlex;
	*ptrEntier += ageSandie;
	cout << "ageAlex est " << ageAlex << endl;

	double* ptrReel;
	ptrReel = &x;
	y += 5 * (*ptrReel);
	cout << "y contient la valeur " << y << endl;
}
 
//]