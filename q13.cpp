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
	int romanToInt(std::string s) {

		int total = 0;
		for (int i = 0; i < s.size(); i++) {
			switch (s[i])
			{
			case 'M':
				total += 1000;
				break;
			case 'D':
				total += 500;
				break;
			case 'C':
				if (i + 1 < s.size() && s[i + 1] == 'D') {
					total += 400;
					i++;
				}
				else if (i + 1 < s.size() && s[i + 1] == 'M') {
					total += 900;
					i++;
				}
				else {
					total += 100;
				}
				break;
			case 'L':
				total += 50;
				break;
			case 'X':
				if (i + 1 < s.size() && s[i + 1] == 'L') {
					total += 40;
					i++;
				}
				else if (i + 1 < s.size() && s[i + 1] == 'C') {
					total += 90;
					i++;
				}
				else {
					total += 10;
				}
				break;
			case 'V':
				total += 5;
				break;
			case 'I':
				if (i + 1 < s.size() && s[i + 1] == 'V') {
					total += 4;
					i++;
				}
				else if (i + 1 < s.size() && s[i + 1] == 'X') {
					total += 9;
					i++;
				}
				else {
					total += 1;
				}
				break;
			default:
				break;
			}
		}

		return total;
	}
};

void test_it(int i, std::string rs) {
	Solution s;
	std::cout << rs << "=>" << i << " == " << s.romanToInt(rs) << " " << (i == s.romanToInt(rs) ? "passed" : "failed") << "\n";
}

int main() {

	test_it(1, "I");
	test_it(2, "II");
	test_it(3, "III");
	test_it(4, "IV");
	test_it(5, "V");
	test_it(6, "VI");
	test_it(7, "VII");
	test_it(8, "VIII");
	test_it(9, "IX");
	test_it(10, "X");
	test_it(34, "XXXIV");
	test_it(58, "LVIII");
	test_it(1994, "MCMXCIV");
	test_it(3999, "MMMCMXCIX");
	getchar();
}