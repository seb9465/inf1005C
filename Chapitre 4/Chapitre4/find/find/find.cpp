#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	cout << "Donner une phrase : ";
	string phrase;
	getline(cin, phrase);

	int position = phrase.find(" ", 0);

	while (position != -1)
	{
		cout << position << endl;
		int positionNouvelle = phrase.find(" ", position + 1);
		position = positionNouvelle;
	}

	for (int i = 0; i < phrase.length(); i++)
	{
		if (phrase[i] == ' ')
		{
			cout << i << endl;
		}
	}
	return 0;
}