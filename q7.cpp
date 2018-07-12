#include "stdafx.h"

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
	// 12 ms
	int reverse(int x) {
		int r = 0;
		while (x != 0) {
			if ((x > 0 && (std::numeric_limits<int>::max() - x % 10) / 10 >= r) ||
				(x < 0 && (std::numeric_limits<int>::min() - x % 10) / 10 <= r)) {
				r = r * 10 + x % 10;
				x = x / 10;
			}
			else {
				return 0;
			}
		}
		return r;
	}
};

int main() {

	Solution s;
	std::cout << s.reverse(123) << "\n\n";
	std::cout << s.reverse(-123) << "\n\n";
	std::cout << s.reverse(120) << "\n\n";
	std::cout << s.reverse(-12) << "\n\n";
	std::cout << s.reverse(1534236469) << "\n\n";

	getchar();
}