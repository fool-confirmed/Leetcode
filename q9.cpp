#include <iostream>
#include <vector>

/*
static auto x = [](){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
return 0;
}();
*/

class Solution {
public:
	bool isPalindrome(int x) {
		std::vector<int> v;
		if (x < 0) {
			return false;
		}
		if (x < 10) {
			return true;
		}
		while (x > 0) {
			int y = x - x / 10 * 10;
			x = x / 10;
			v.push_back(y);
		}
		for (int i = 0; i < v.size() / 2; i++)
		{
			if (v[i] != v[v.size() - 1 - i]) {
				return false;
			}
		}
		return true;

	}
};

int main() {

	Solution s;

	std::cout << s.isPalindrome(-0) << "\n";
	std::cout << s.isPalindrome(121) << "\n";

	std::cout << "\nExpected 0: \n";
	std::cout << s.isPalindrome(10) << "\n";
	std::cout << s.isPalindrome(345) << "\n";
	std::cout << s.isPalindrome(-1) << "\n";

	getchar();
}