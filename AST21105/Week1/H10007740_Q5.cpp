#include <iostream>
using namespace std;

int main() {
	double celsius = 0;
	cout << "\u00b0C to \u00b0F calculator" << endl;
	cout << "Please input temperature in celsius: ";
	cin >> celsius;

	double farenheit = (celsius * 9.0 / 5.0) + 32;
	cout << celsius << "\u00b0C = " << farenheit << "\u00b0F" << endl;
	return 0;
}
