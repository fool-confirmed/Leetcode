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

// O(N)
int isPalindromic(std::string s) {
	int len = s.length(); std::cout << s << "\n";
	for (int i = 0; i < len / 2; i++) {
		if (s.at(i) != s.at(len - 1 - i)) {
			return 0;
		}
	}
	return s.length();
}

int isSubStrPalindromic(std::string s, int startIndex, int endIndex) {
	int len = endIndex - startIndex + 1;
	for (int i = 0; i < len / 2; i++) {
		if (s.at(startIndex + i) != s.at(endIndex - i)) {
			return 0;
		}
	}
	return len;
}

class Solution {
public:
	// O(N^3)
	std::string longestPalindrome_01(std::string s) {
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
	// O(N^3)
	std::string longestPalindrome_02(std::string s) {

		if (s.length() == 1) { return s; }

		for (int maxLen = s.length(); maxLen > 1; maxLen--) {
			int reduce = s.length() - maxLen;
			int left = 0;
			int right = s.length() - 1 - reduce;
			while (left <= reduce)
			{
				if (isSubStrPalindromic(s, left, right))
				{
					return s.substr(left, right - left + 1);
				}
				left++;
				right++;
			}
		}
		return s.substr(0, 1);
	}

	std::string longestPalindrome(std::string s) {
		int maxLen = 0, step = 0, left = 0, right = 0;
		for (int i = 0; i < s.length(); i++) {
			step = 0;
			while ((i - step >= 0 && i + 1 + step <= s.length() - 1) && (s.at(i - step) == s.at(i + 1 + step))) {
				step++;
			}
			step--;
			if (step >= 0 && i + 1 + step - (i - step) + 1 > maxLen) {
				left = i - step;
				right = i + 1 + step;
				maxLen = right - left + 1;
			}

			step = 0;
			while ((i - 1 - step >= 0 && i + 1 + step <= s.length() - 1) && (s.at(i - 1 - step) == s.at(i + 1 + step))) {
				step++;
			}
			step--;
			if (step >= 0 && (i + 1 + step - (i - 1 - step)) + 1 > maxLen) {
				left = i - 1 - step;
				right = i + 1 + step;
				maxLen = right - left + 1;
			}
		}
		return s.substr(left, right - left + 1);
	}
};

int main() {

	Solution s;

	std::cout << "a :" << s.longestPalindrome("a") << "\n";
	std::cout << "bb :" << s.longestPalindrome("bb") << "\n";
	std::cout << "ccc :" << s.longestPalindrome("ccc") << "\n";
	std::cout << "cbbd :" << s.longestPalindrome("cbbd") << "\n";
	std::cout << "abcda :" << s.longestPalindrome("abcda") << "\n";
	std::cout << "bbbabb :" << s.longestPalindrome("bbbabb") << "\n";
	std::cout << "aaabaaaa :" << s.longestPalindrome("aaabaaaa") << "\n";
	std::cout << "illi: " << s.longestPalindrome("iptmykvjanwiihepqhzupneckpzomgvzmyoybzfynybpfybngttozprjbupciuinpzryritfmyxyppxigitnemanreexcpwscvcwddnfjswgprabdggbgcillisyoskdodzlpbltefiz") << "\n";
	std::cout << "ranynar: " << s.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") << "\n";
	std::cout << "a[m]bca[n]: " << s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << "\n";

	std::cout << "aaaaaaaaaabcaaaaaaaaaa :" << s.longestPalindrome("aaaaaaaaaabcaaaaaaaaaa") << "\n";

	// print length if palindromic, or zero
	/*std::cout << isPalindromic("babab") << "\n";
	std::cout << isPalindromic("abccba") << "\n";
	std::cout << isPalindromic("bbbabb") << "\n";
	std::cout << isPalindromic("cbbd") << "\n";
	std::cout << isPalindromic("a") << "\n";*/

	/*std::cout << isSubStrPalindromic("babab", 0, 4) << "\n";
	std::cout << isSubStrPalindromic("abccba", 0, 5) << "\n";
	std::cout << isSubStrPalindromic("bbbabb", 0, 5) << "\n";
	std::cout << isSubStrPalindromic("cbbd", 0, 3) << "\n";
	std::cout << isSubStrPalindromic("a", 0, 0) << "\n";*/

	getchar();
}