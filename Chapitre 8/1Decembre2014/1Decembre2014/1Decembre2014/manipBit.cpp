#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int  main()
{
	
	// vérifier si un nombre est impair

	unsigned nombre;
	cout << " donner un nombre ";
	cin >> nombre;

	if ((nombre & 0x1) == 1)
		cout << "nombre impair" << endl;
	else
		cout << "nombre pair" << endl;


	// vérifier si  le troisième bit est à 1.
	unsigned valeur = 0xF6;
	if ((valeur | 0x4) == 0xF6)
		cout << "3ieme bit a 1" << endl;
	else
		cout << "non";
	// http://fr.wikipedia.org/wiki/IPv4

	// entete d'un paquet IP4 contenu sur un unsigned int
	// 4 bits pour la version IP
	//  4 bits pour la longueur de l'entête
	//  8 bits pour le type de service
	//  longueur totale en octets

	short version = 4;
	short longueurEntete = 6;
	short typeService = 0x2C;
	int longueurTotal = 56788;

	 // mettre toutes ces infos  dans un  unsigend int
	unsigned enteteIP4_23bits = 56788;
	enteteIP4_23bits = typeService << 16 | enteteIP4_23bits;
	enteteIP4_23bits = longueurEntete << 24 | enteteIP4_23bits;
	enteteIP4_23bits = version << 28 | enteteIP4_23bits;
	cout << "en base 10 " << enteteIP4_23bits << endl;
	cout << "en base 16 " << hex << enteteIP4_23bits << endl;
	cout <<dec;
	// on fait l'inverse
	cout << "daalda" << enteteIP4_23bits << endl;
	cout << "version " << ((enteteIP4_23bits & 0xF0000000) >> 28) << endl;
	cout << "longueur Entete " << ((enteteIP4_23bits & 0xF000000) >> 24) << endl;
	cout << "typeService " << ((enteteIP4_23bits & 0xFF0000) >> 16) << endl;
	cout << "longueurTotal " << (enteteIP4_23bits & 0xFFFF) << endl;



	return 0;

}