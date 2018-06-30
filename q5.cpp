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
	int len = s.length(); //std::cout << s << '\n';
	for (int i = 0; i < len / 2; i++) {
		if (s.at(i) != s.at(len - 1 - i)) {
			return 0;
		}
	}
	return s.length();
}

class Solution {
public:
	std::string longestPalindrome(std::string s) {
		if (s.length() == 1) { return s; }
		int indexFound, maxLen = 0;
		std::string retval;

		for (int i = 0; i < s.length(); i++) {
			indexFound = s.find(s.at(i), i + 1);
			while (indexFound != s.npos)
			{
				int l = isPalindromic(s.substr(i, indexFound - i + 1));
				if (l > maxLen) {
					maxLen = l;
					retval = s.substr(i, indexFound - i + 1);
				}
				if (maxLen == s.length()) {
					return s;
				}
				indexFound = s.find(s.at(i), indexFound + 1);
			}
		}
		if (retval.empty()) { retval = s.at(0); }
		return retval;
	}
};


int main() {

	Solution s;

	std::cout << "bbbabb :" << s.longestPalindrome("bbbabb") << "\n";
	std::cout << "a :" << s.longestPalindrome("a") << "\n";
	std::cout << "bb :" << s.longestPalindrome("bb") << "\n";
	std::cout << "abcda :" << s.longestPalindrome("abcda") << "\n";
	std::cout << "aaabaaaa :" << s.longestPalindrome("aaabaaaa") << "\n";
	std::cout << "ranynar: " << s.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") << "\n";

	std::cout << "cbbd :" << s.longestPalindrome("cbbd") << "\n";

	// print length if palindromic, or zero
	/*std::cout << isPalindromic("babab") << "\n";
	std::cout << isPalindromic("abccba") << "\n";
	std::cout << isPalindromic("bbbabb") << "\n";
	std::cout << isPalindromic("cbbd") << "\n";
	std::cout << isPalindromic("a") << "\n";*/

	getchar();
}