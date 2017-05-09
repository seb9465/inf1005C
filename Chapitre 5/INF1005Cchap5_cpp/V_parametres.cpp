#include <iostream>
using namespace std;
//[
double calculerMinimum(double a, double b)
{
	double minimum;
	if (a <= b)
		minimum = a;
	else
		minimum = b;
	return minimum;
}

int main()
{
	double nombre1 = 12.3,
	       nombre2 = -5.14,
	       minimum;
	minimum = calculerMinimum(nombre1, nombre2);


	cout << "Le plus petit est " << minimum << endl;
}

//]
// vim: ts=4