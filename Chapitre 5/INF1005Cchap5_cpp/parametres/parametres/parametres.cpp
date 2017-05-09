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

double calculerMaximum(double a, double b)
{
	double maximum;
	if (a >= b)
		maximum = a;
	else
		maximum = b;
	return maximum;
}

int main()
{
	double nombre1 = 12.3,
		nombre2 = -5.14,
		minimum,
		maximum;
	minimum = calculerMinimum(nombre1, nombre2);
	maximum = calculerMaximum(nombre1, nombre2);

	cout << "Nombre 1 : " << nombre1 << endl;
	cout << "Nombre 2 : " << nombre2 << endl;
	cout << "Le plus petit est " << minimum << endl;
	cout << "Le plus grand est " << maximum << endl;
}

//]
// vim: ts=4