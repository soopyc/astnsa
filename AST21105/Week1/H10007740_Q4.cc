#include <iostream>
using namespace std;

int main() {
	const double PI = 3.1415926;
	double radius = 0;
	cout << "Please enter the radius of the circle to calculate the area: ";
	cin >> radius;
	double area = PI * radius * radius;
	cout << "The area is " << area << " units squared." << endl;
	return 0;
}
