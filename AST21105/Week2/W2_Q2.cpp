#include <iostream>
#include <string>

/**
 * Return a lowercase string for a given `orig` string.
 */
std::string tolower_s(std::string orig) {
	std::string result = "";
	for (char chr : orig) {
		result += tolower(chr);
	}
	return result;
}

int main() {
	std::string str1 = "i am john wick";
	std::string str2 = "I am John Wick";

	// prepare lowercase strings for comparison
	std::string str1_lower = tolower_s(str1);
	std::string str2_lower = tolower_s(str2);

	// task requirements
	std::cout << "str1 " << (str1.compare(str2) == 0 ? "is" : "is not") << " lexicographically equal to msg2." << std::endl;
	std::cout << "str1_lower " << (str1_lower.compare(str2_lower) == 0 ? "is" : "is not") << " lexicographically equal to msg2_lower." << std::endl;
	std::cout << "concatenation of str1 and str2: " << str1 + str2 << std::endl;

	return 0;
}
