//[
#include <iostream>
#include <iomanip>
using namespace std;

// Computes the total cost, including 5% sales tax,
// on nItems items at a cost of itemPrice each.
double totalCost(int nItems, double itemPrice)
{
	static const double TAXRATE = 0.05; // 5% sales tax
	double subtotal = itemPrice * nItems;
	return subtotal + subtotal*TAXRATE;
}

int main()
{
	double pricePerItem;
	int numberOfItems;
	cout << "Enter the number of items purchased: ";
	cin >> numberOfItems;
	cout << "Enter the price per item $";
	cin >> pricePerItem;

	double bill = totalCost(numberOfItems, pricePerItem);

	cout << fixed << showpoint << setprecision(2);
	cout << numberOfItems << " items at "
	     << "$" << pricePerItem << " each." << endl
	     << "Final bill, including tax, is $" << bill
	     << endl;
}
//]