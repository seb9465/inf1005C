/**
* Déplacement d'un robot.
* \fichier   Exercice7.cpp
* \auteur Sebastien Cadorette & Yanis Bouhraoua
* \date   11 octobre 2014
* Créé le 9 octobre 2014
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//Initialisation des variables
	const int ORIGINE_X = 0,
		ORIGINE_Y = 0;

	int coordonneeX = ORIGINE_X,
		coordonneeY = ORIGINE_Y;

	//Lecture du fichier
	ifstream lecture("robot.txt");

	if (lecture.fail())
	{
		cout << "Probleme d'ouverture." << endl;
	}
	else
	{
		while (lecture.peek()!=EOF)
		{
			//Lecture ligne par ligne du fichier
			string ligne;
			getline(lecture, ligne);
			
			//Comparaison pour déterminer le mouvement à effectuer
			if (ligne == "HAUT")
			{
				++coordonneeY;
			}
			else if (ligne == "BAS")
			{
				--coordonneeY;
			}
			else if (ligne == "DROITE")
			{
				++coordonneeX;
			}
			else if (ligne == "GAUCHE")
			{
				--coordonneeX;
			}
		}

		//Affichage des coordonnées finales
		cout << "Coordonnees finales : (" << coordonneeX << ", "
			<< coordonneeY << ")." << endl;
	}




	return 0;
}