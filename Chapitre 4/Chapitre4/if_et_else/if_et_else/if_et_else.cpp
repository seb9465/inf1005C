#include <iostream>

using namespace std;

int main()
{
	cout << "Entrez une note : " << endl;

	int note = 0;

	cin >> note;

	/*if (note >= 90 && note <= 100)
	{
	cout << 'A' << endl;
	}
	else
	{
	if (note >= 80)
	{
	cout << 'B' << endl;
	}
	else
	{
	if (note >= 70)
	{
	cout << 'C' << endl;
	}
	}
	}*/


	if (note >= 90 && note <= 100)
	{
		cout << 'A' << endl;
	}
	else if (note >= 80)
	{
		cout << 'B' << endl;
	}
	else if (note >= 70)
	{
		cout << 'C' << endl;
	}
	else if (note >= 60)
	{
		cout << 'D' << endl;
	}
	else
	{
		cout << "Echec" << endl;
	}

	return 0;
}