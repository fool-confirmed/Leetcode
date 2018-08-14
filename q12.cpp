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
private:
	std::string formatSingle(int i, char s0, char s1, char s2) {
		std::string s;
		switch (i)
		{
		case 1:
			s.push_back(s0);
			break;
		case 2:
			s.push_back(s0); s.push_back(s0);
			break;
		case 3:
			s.push_back(s0); s.push_back(s0); s.push_back(s0);
			break;
		case 4:
			s.push_back(s0); s.push_back(s1);
			break;
		case 5:
			s.push_back(s1);
			break;
		case 6:
			s.push_back(s1); s.push_back(s0);
			break;
		case 7:
			s.push_back(s1); s.push_back(s0); s.push_back(s0);
			break;
		case 8:
			s.push_back(s1); s.push_back(s0); s.push_back(s0); s.push_back(s0);
			break;
		case 9:
			s.push_back(s0); s.push_back(s2);
			break;
		default:
			break;
		}
		return s;
	}
public:
	std::string intToRoman(int num) {
		if (num < 1 || num >3999) { return ""; }

		std::string s;
		int temp = num % 10;
		s = formatSingle(temp, 'I', 'V', 'X');

		num = num / 10;
		if (num > 0) {
			temp = num % 10;
			s.insert(0, formatSingle(temp, 'X', 'L', 'C'));

			num = num / 10;
			if (num > 0) {
				temp = num % 10;
				s.insert(0, formatSingle(temp, 'C', 'D', 'M'));

				num = num / 10;
				if (num > 0) {
					temp = num % 10;
					s.insert(0, formatSingle(temp, 'M', '?', '?'));
				}
			}
		}
		return s;
	}
};

void test_it(int i, std::string rs) {
	Solution s;
	std::cout << i << "=>" << rs << " == " << s.intToRoman(i) << " " << (rs == s.intToRoman(i) ? "passed" : "failed") << "\n";
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

	getchar();
}