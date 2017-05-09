#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//[
struct Point {
	double x, y;
};
//]
void imprimerPoint(const Point& point)
{
	cout << "(" << point.x << ", " << point.y << ")";
}

void fonction1()
{//[ Déclaration et initialisation d'un enregistrement:
	Point point = { 12.3, -1.34 };
//]
	imprimerPoint(point);
//[ Accès aux champs d'un enregistrement:
	point.x = -2.5; point.y = -6.78;
//]
	imprimerPoint(point);
	cout << endl;
}

double aleatoireReelZeroUn()
{
	return (rand() % 1000) / 1000.0;
}

Point pointAleatoire()
{
	Point point = { aleatoireReelZeroUn(), aleatoireReelZeroUn() };
	return point;
}

void fonction2()
{
	srand(unsigned(time(nullptr)));
	//[
	Point pointA, pointB, vecteur[10];
	//]
	//[
	pointA.x = 12.3;
	pointA.y = -5.11;
	//]
	//[
	pointB = pointA;
	//]
	for (int i = 0; i < 10; i++)
		vecteur[i] = pointAleatoire();
	
	//[ Comparaison de deux enregistrements:
	bool pareil = false;
	if (pointA.x == pointB.x && pointA.y == pointB.y)
		pareil = true;
	//]
	cout << "pareil = " << pareil << endl;
	//[ Le plus petit x du vecteur:
	double minX = vecteur[0].x;
	for (int i = 1; i < 10; i++)
		if (vecteur[i].x < minX)
			minX = vecteur[i].x;
	//]
	cout << "minX = " << minX << endl;
}

int main()
{
	cout << boolalpha;
	fonction1();
	fonction2();
}

