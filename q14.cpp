#include <iostream>
#include <string>
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
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		if (strs.size() == 0) { return ""; }
		if (strs.size() == 1) { return strs[0]; }
		std::string prefix = "";
		int p = 0, d = 0;
		while (d == 0) {
			char temp = p < strs[0].size() ? strs[0][p] : '0';
			for (int i = 1; i < strs.size(); i++) {
				if (p < strs[i].size() && temp == strs[i][p]) {
					continue;
				}
				else {
					d = 1;
					break;
				}
			}
			if (d == 0) {
				prefix.push_back(temp);
				p++;
			}
		}
		return prefix;
	}
};

int main() {
	Solution s;
	std::vector<std::string> v1;
	std::cout << s.longestCommonPrefix(v1) << "(empty)\n";

	v1.push_back("a");
	std::cout << s.longestCommonPrefix(v1) << "\n";
	v1.clear();

	v1.push_back("flower");
	v1.push_back("flow");
	v1.push_back("flight");
	std::cout << s.longestCommonPrefix(v1) << "\n";

	v1.clear();
	v1.push_back("dog");
	v1.push_back("racecar");
	v1.push_back("car");
	std::cout << s.longestCommonPrefix(v1) << "\n";

	getchar();
}