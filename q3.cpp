#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:

	// 335ms
	int lengthOfLongestSubstring_1(std::string s) {
		int maxLength = 0, currentLen = 0;
		std::unordered_set<char> mySet;
		for (unsigned j = 0; j < s.length(); j++) {
			unsigned i = j;
			while (!mySet.count(s[i]) && i < s.length())
			{
				currentLen++;
				mySet.insert(s[i]);
				i++;
			}
			maxLength = currentLen > maxLength ? currentLen : maxLength;
			if ((s.length() - j <= maxLength)) {
				return maxLength;
			}
			mySet.clear();
			currentLen = 0;
		}
		return maxLength;
	}

	// 28ms after read the solution
	int lengthOfLongestSubstring(std::string s) {
		int maxLength = 0;
		std::unordered_map<char, int> myMap;
		for (unsigned i = 0, j = 0; j < s.length(); j++) {
			if (!myMap.count(s[j]))
			{
				myMap.insert({ s[j], j });
			}
			else {
				i = myMap.find(s[j])->second + 1 > i ? myMap.find(s[j])->second + 1 : i;
				myMap.find(s[j])->second = j;
			}
			maxLength = j - i + 1 > maxLength ? j - i + 1 : maxLength;
		}
		return maxLength;
	}

	void printSet(std::unordered_set<char> mySet) {
		for (auto it = mySet.begin(); it != mySet.end(); it++) {
			std::cout << *it;
		}
		std::cout << '\n';
	}
};

int main()
{
    std::string myString("abcabcbb");

    Solution s = Solution();
    std::cout << "3 = " << s.lengthOfLongestSubstring(myString) << '\n';

	myString = "bbbbb";
	std::cout << "1 = " << s.lengthOfLongestSubstring(myString) << '\n';

	myString = "pwwkew";
	std::cout << "3 = " << s.lengthOfLongestSubstring(myString) << '\n';

	myString = "aab";
	std::cout << "2 = " << s.lengthOfLongestSubstring(myString) << '\n';

	myString = "dvdf";
	std::cout << "3 = " << s.lengthOfLongestSubstring(myString) << '\n';

	myString = "asjrgapa";
	std::cout << "6 = " << s.lengthOfLongestSubstring(myString) << '\n';

	myString = "aabcedafghij";
	std::cout << s.lengthOfLongestSubstring(myString) << '\n';

	myString = "abba";
	std::cout << "2 = " << s.lengthOfLongestSubstring(myString) << '\n';

	getchar();
    return 0;
}
