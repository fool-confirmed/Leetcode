#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::cout << s;
        return 0;
    }
};

int main()
{
    std::string myString("test string");
    Solution s = Solution();
    s.lengthOfLongestSubstring(myString);
    return 0;
}
