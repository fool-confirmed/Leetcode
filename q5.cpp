#include <iostream>
#include <string>
#include <cstring>


/*
static auto x = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();
*/

int isPalindromic(std::string s) {
	int len = s.length();
	if (len % 2 == 0) {
		//even
		for (int i = 0; i < len / 2 ; i++) {
			if (s.at(i) != s.at(len - 1 - i)) {
				return 0;
			}
		}
	}
	else {
		//odd
		for (int i = 0; i < len / 2 ; i++) {
			if (s.at(i) != s.at(len - 1 - i)) {
				return 0;
			}
		}
	}


	return s.length();
}

class Solution {
public:
	std::string longestPalindrome(std::string s) {
		const char* arr = s.c_str();
		int end, maxLen = 0;
		std::string retval;

		for (int i = 0; i < s.length(); i++) {
			end = strrchr(arr, arr[i]) - arr - i;std::cout << end << "\n";
			if (end >= 0) {
				int l = isPalindromic(s.substr(i, end + 1));
				if (l > maxLen) {
					maxLen = l;
					retval = s.substr(i, end + 1);
				}
			}
		}

		return retval;
	}
};


int main() {

	Solution s;

	//std::cout << "bbbabb :" << s.longestPalindrome("bbbabb") << "\n";
	//std::cout << "a :" << s.longestPalindrome("a") << "\n";
	std::cout << "abcda :" << s.longestPalindrome("abcda") << "\n";
	std::cout << "aaabaaaa :" << s.longestPalindrome("aaabaaaa") << "\n";
	// print length if palindromic, or zero
	/*std::cout << isPalindromic("babab") << "\n";
	std::cout << isPalindromic("abccba") << "\n";
	std::cout << isPalindromic("bbbabb") << "\n";
	std::cout << isPalindromic("cbbd") << "\n";
	std::cout << isPalindromic("a") << "\n";*/

	getchar();
}