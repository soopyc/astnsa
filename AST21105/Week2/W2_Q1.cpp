#include <iostream>

int main() {
	int x, y;
	std::cout << "Input 2 integers separated by spaces: ";
	std::cin >> x >> y;

	std::cout << "Sum of " << x << " + " << y << " = " << (x + y) << std::endl;
	std::cout << "Difference of " << x << " - " << y << " = " << (x - y) << std::endl;
	std::cout << "Product of " << x << " * " << y << " = " << (x * y) << std::endl;
	std::cout << "Quotient of " << x << " / " << y << " = " << ((double)x / (double)y) << std::endl;
	std::cout << "Modulo of " << x << " % " << y << " = " << (x % y) << std::endl;

	return 0;
}
