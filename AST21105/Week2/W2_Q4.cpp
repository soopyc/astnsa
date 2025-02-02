#include <iostream>
#include <string>

int main() {
	std::string input;
	int input_int;
	int count = 0;
	int sum = 0;

	while (true) {
		std::cout << "Please enter a positive integer (stop with -1): ";
		std::getline(std::cin, input); // get a line of input
		if (std::cin.eof()) // explode if we get an eof.
			break;
		// please give me my rust back
		try {
			input_int = std::stoi(input); // set input_int to parsed value.
		} catch (std::invalid_argument) {
			// can't convert, probably a string or something
			std::cerr << "That is not a valid input." << std::endl;
			continue;
		} catch (std::out_of_range) {
			// out of range
			std::cerr << "That number is out of range." << std::endl;
			continue;
		}

		if (input_int == -1) {
			break;
		} else if (input_int < -1) {
			std::cerr << "That is not a valid positive integer." << std::endl;
			continue;
		} else {
			count++;
			sum += input_int;
		}
	}

	std::cout << "# of valid integers input: " << count << std::endl;
	std::cout << "sum of integers: " << sum << std::endl;

	return 0;
}
