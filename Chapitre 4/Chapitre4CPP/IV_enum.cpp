/**
*  Exemple avec le type énumération.
*/
#include <iostream>
#include <ctime>    // Pour time.
#include <cstdlib>  // Pour srand, rand.
using namespace std; //[
int main()
{
	enum  Direction { NORD, SUD, EST, OUEST };

	srand(unsigned(time(0)));
	int x = rand() % 21;
	int y = rand() % 21;

	cout << "Positon initiale du point: ";
	cout << '(' << x << ',' << y << ')' << endl;

	Direction direction = Direction(rand() % 4);
	switch (direction) {
		case NORD  : if (y < 20) ++y; break;
		case SUD   : if (y > 0)  --y; break;
		case EST   : if (x < 20) ++x; break;
		case OUEST : if (x > 0)  --x;
	}

	cout << "Positon finale du point  : ";
	cout << '(' << x << ',' << y << ')' << endl;
}

//]
// vim: ts=3