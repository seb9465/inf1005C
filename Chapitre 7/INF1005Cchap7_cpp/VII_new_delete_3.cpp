#include <iostream>
using namespace std;
//[
struct Date {
	int mois;
	int jour;
	int annee;
};

int main()
{
	Date* ptrDate;
	ptrDate = new Date;
	ptrDate->mois = 10;
	ptrDate->jour = 18;
	ptrDate->annee = 1938;
	cout << ptrDate->mois << "/"  << ptrDate->jour << "/"
	     << ptrDate->annee << endl;
	delete ptrDate;
	ptrDate = 0;
}

//]