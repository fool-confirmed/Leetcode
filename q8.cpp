#include <iostream>
#include <string>

/*
static auto x = [](){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
return 0;
}();
*/

class Solution {
public:
	int myAtoi(std::string str) {

		unsigned int i1 = 0, i2 = 0;

		while (i1 < str.length())
		{
			if (str[i1] == ' ') {
				i1++;
			}
			else if (str[i1] == '+' || str[i1] == '-' || (str[i1] >= '0' && str[i1] <= '9')) {
				break;
			}
			else {
				std::cout << "Not start with a number\n";
				return 0;
			}
		}
		i2 = i1 + 1;

		while (i2 < str.length() && (str[i2] >= '0' && str[i2] <= '9')) {
			i2++;
		}
		std::string numStr = str.substr(i1, i2 - i1);
		std::cout << "found raw number string: " << numStr << "\n";

		if (numStr.length() == 0) {
			return 0;
		}

		if (numStr[0] == '-' || numStr[0] == '+')
		{
			while (numStr.length() > 1 && numStr[1] == '0') {
				numStr.erase(1, 1);
			}
		}
		else {
			while (numStr.length() > 1 && numStr[0] == '0') {
				numStr.erase(0, 1);
			}
		}
		if (numStr == "-" || numStr == "+") {
			return 0;
		}
		if (numStr[0] == '+') {
			numStr.erase(0, 1);
		}
		std::cout << "cleaned number string: " << numStr << "\n";

		if (numStr[0] == '-') {
			if (numStr.length() > 11) {
				return std::numeric_limits<int>::min();
			}
			else if (numStr.length() == 11) {
				if (std::stoi(numStr.substr(0, 10)) < -214748364 || (std::stoi(numStr.substr(0, 10)) == -214748364 && std::stoi(numStr.substr(10, 1)) > 8)) {
					return std::numeric_limits<int>::min();
				}
			}
		}
		else {
			if (numStr.length() > 10) {
				return std::numeric_limits<int>::max();
			}
			else if (numStr.length() == 10) {
				if (std::stoi(numStr.substr(0, 9)) > 214748364 || (std::stoi(numStr.substr(0, 9)) == 214748364 && std::stoi(numStr.substr(9, 1)) > 7)) {
					return std::numeric_limits<int>::max();
				}
			}
		}
		//Max 32 - bit Int : 2147483647
		//Min 32 - bit Int : -2147483648
		return std::stoi(numStr);

	}
};

int main() {

	Solution s;

	/*std::cout << "Max 32-bit Int: " << std::numeric_limits<int>::max() << "\n";
	std::cout << "Min 32-bit Int: " << std::numeric_limits<int>::min() << "\n";
	*/

	std::cout << "test: " << s.myAtoi("           ") << "\n";
	std::cout << "test: " << s.myAtoi("    41       ") << "\n";
	std::cout << "test: " << s.myAtoi("     -41      ") << "\n";
	std::cout << "test: " << s.myAtoi("  word 345      ") << "\n";
	std::cout << "test: " << s.myAtoi("-91283472332") << "\n";
	std::cout << "test: " << s.myAtoi("2147483647") << "\n";
	std::cout << "test: " << s.myAtoi("2147483648") << "\n";
	std::cout << "test: " << s.myAtoi("-2147483648") << "\n";
	std::cout << "test: " << s.myAtoi("-2147483649") << "\n";
	std::cout << "test: " << s.myAtoi("+") << "\n";
	std::cout << "test: " << s.myAtoi("-") << "\n";
	std::cout << "test: " << s.myAtoi("  0000000000012345678") << "\n";

	std::cout << "test: " << s.myAtoi("    +1146905820n1") << "\n";

	getchar();
}