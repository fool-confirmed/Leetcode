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
		int Ld = numRows;
		int Lu = numRows <= 2 ? 0 : numRows - 2;

		char** arr = new char*[numRows];
		for (int i = 0; i < numRows; i++) {
			arr[i] = new char[s.length()];
		}
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < s.length(); j++) {
				arr[i][j] = ' ';
			}
		}

		for (int i = 0; i < s.length(); i++) {

			int c = i / L;
			int p = i % L;
			int x = c * (numRows == 1 ? numRows : numRows - 1), y = 0;
			if (0 <= p && p <= Ld - 1) {
				y = p;
			}
			else if (Ld <= p && p <= L - 1) {
				x = x + p - (numRows - 1);
				y = numRows - 1 - (p + 1 - numRows);
			}
			arr[y][x] = s[i];

		}

		std::string retval;
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < s.length(); j++) {
				if(arr[i][j] != ' '){
					retval.push_back(arr[i][j]);
				}
			}

		}
		return retval;
	}
};

/*
circle L(n) = | n == 1, L = 1 | L = 2n - 2
down part Ld = n
up part Lu = | n <= 2, Lu = 0 | Lu = n - 2
given an index i, row number n > 1, relative index p = i % (2n -2)
if 0 <= p <= Ld - 1, down part
if Ld <= p <= L - 1, up part
e.g. n = 3, L = 4, Lu = 1, Ld = 3, down [0, 2], up [3, 3]
n = 4, L = 6, Ld = 4, Lu = 2, down [0, 3], up [4, 5]
*/
void displayZigZag(std::string sample, int n, bool showDetails){

	int L = n == 1 ? 1 : 2 * n - 2;
	int Ld = n;
	int Lu = n <= 2 ? 0 : n - 2;

	// create 2d array
	char** arr = new char*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[sample.length()];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sample.length(); j++) {
			arr[i][j] = ' ';
		}
	}

	for (int i = 0; i < sample.length(); i++) {

		int c = i / L; // which circle it is in
		int p = i % L; // relative index in a circle
		if (showDetails) {
			std::cout << sample[i] << ": circle=" << c << ", p=" << p << ", ";
		}

		int x = c * (n == 1 ? n : n - 1), y = 0; // x->col, y->row, left up cornor is (0, 0), as writing in the pattern
		if (0 <= p && p <= Ld - 1) {
			y = p;
		}
		else if (Ld <= p && p <= L - 1) {
			x = x + p - (n - 1);
			y = n - 1 - (p + 1 - n);
		}
		arr[y][x] = sample[i];
		if (showDetails) {
			std::cout << "(" << x << ", " << y << ")\n";
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sample.length(); j++) {
			std::cout << arr[i][j];
		}
		std::cout << "\n";
	}
}

int main() {

	Solution s;
	std::cout << s.convert("PAYPALISHIRING", 3) << "\n\n";
	std::cout << s.convert("A", 1) << "\n\n";
	std::cout << s.convert("AB", 1) << "\n\n";

	//displayZigZag("AB", 1, true);

	getchar();
}