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
	/*
	from 0 to numRows - 1, reverse calculate which index fix
	*/
	std::string convert(std::string s, int numRows) {
		int L = numRows == 1 ? 1 : 2 * numRows - 2;

		for(int i = 0; i < s.length(); i++){
			std::cout << s[i] << ": circle=" << i / L << ", p=" << i % (2 * numRows - 2) << ")\n";
		}
		return "";
	}
};

/*
circle L(n) = | n == 1, L = 1 | L = 2n - 2
down part Ld = n
up part Lu = | n <= 2, Lu = 0 | Lu = n - 2
given an index i, row number n > 1, relative index p = i % (2n -2)
if 0 < p < Ld - 1, down part
if Ld <= p <= L - 1, up part
e.g. n = 3, L = 4, Lu = 1, Ld = 3, down (0, 2), up [3, 3]
n = 4, L = 6, Ld = 4, Lu = 2, down (0, 3), up [4, 5]
*/
int main() {

	Solution s;


	int n = 3;
	std::string sample = "abcdefg";
	int L = n == 1 ? 1 : 2 * n - 2;

	for (int i = 0; i < sample.length(); i++) {
		std::cout << sample[i] << ": circle=" << i / L << ", p=" << i % (2 * n - 2) << ")\n";
	}

	getchar();
}