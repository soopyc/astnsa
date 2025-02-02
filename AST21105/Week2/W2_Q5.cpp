#include <iostream>
#include <string>
#include <cmath>

bool is_armstrong(int input) {
	// i thought of 2 ways of doing this:
	// - modulo the numbers and do the calculation
	// - for each character convert it back to an int and do the dance
	// i ended up doing it this way because i'm already converting it to a string for the length anyways and this seemed
	// simpler. this probably yields bad code though.

	// unlike javascript or other bad langauges this doesn't copy the pointer to the object.
	// ... we probably don't need this though.
	// int working = input;

	// find the number of digits of the input.
	std::string input_s = std::to_string(input);
	int length = input_s.length();
	int result = 0;

	for (char i : input_s) {
		// HACK: i don't like this at *all* but this seems logical because we don't have a magic int() function
		// feel free to reach out if you have a better solution - i'm eager to learn.
		int current = i - '0'; // works with ascii and unicode because whatever int - chr(48) should yield the number
		result += std::pow(current, length);
	}

	return result == input;
}

int main() {
	int int1, int2; // storage of user input
	int count = 0; // count of armstrong numbers

	std::cout << "Please enter 2 integers to find armstrong numbers between them: ";
	std::cin >> int1 >> int2;

	if (std::cin.fail() || std::cin.eof()) {
		std::cout << "invalid input, exiting." << std::endl;
		return 1;
	}
	if (int2 < int1) {
		std::cerr << "the second integer must be larger than the first integer." << std::endl;
		return 1;
	}

	std::cout<< "Armstrong numbers found: ";
	for (int i = int1; i <= int2; i++) {
		// haven't learned arrays yet, save me new Vec();
		if (is_armstrong(i)) {
			count++;
			std::cout << i << " ";
		}
	}

	if (count <= 0) {
		std::cout << "(couldn't find any)" << std::endl;
	} else {
		std::cout << "(" << count << " integers)" << std::endl;
	}
}
