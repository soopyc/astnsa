#include <iostream>
#include <string>

const std::string VOWELS = "aeiou";
const std::string CONSONANTS = "bcdfghjklmnpqrstvwxyz";

int main() {
	std::string input = "";
	int vowel_count = 0;
	int consonant_count = 0;
	int others_count = 0;

	std::cout << "Enter a string: ";
	// get an entire line of input
	getline(std::cin, input);

	for (char chr : input) {
		// probably the worst solution you'd ever see
		if (VOWELS.find(chr) != VOWELS.npos) // if the character can be found in the vowels string surely it is a vowel
			vowel_count++;
		else if (CONSONANTS.find(chr) != CONSONANTS.npos) // likewise
			consonant_count++;
		else // i feel like this is just duck typing
			others_count++;
	}

	std::cout << "# of vowels: " << vowel_count << std::endl;
	std::cout << "# of consonants: " << consonant_count << std::endl;
	std::cout << "# of other characters: " << others_count << std::endl;

	return 0;
}
