#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
/*
static auto x = [](){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
return 0;
}();
*/
bool fncomp(int lhs, int rhs) { return lhs > rhs; }
class Solution {
public:
	int maxArea(vector<int>& height) {
		return test1(height);
	}

	int test2(vector<int>& height) {

		int area = 0;

		bool(*fn_pt)(int, int) = fncomp;
		multimap<int, int, bool(*)(int, int)>origin(fn_pt);
		for (int i = 0; i < height.size(); i++) {
			origin.insert(pair<int, int>(height[i], i));
		}

		set<int> indices;
		int w = origin.begin()->second;
		indices.insert(origin.begin()->second);
		origin.erase(origin.begin());

		while (!origin.empty() && area / (height.size() - 1) < origin.begin()->first)
		{
			int temp = max(abs(origin.begin()->second - *indices.begin()), abs(origin.begin()->second - *indices.rbegin())) * origin.begin()->first;
			if (temp > area) {
				area = temp;
			}

			indices.insert(origin.begin()->second);
			origin.erase(origin.begin());
		}

		return area;

	}

	int test1(vector<int>& height) {

		int max = 0, left = 0, right = 0;
		int v = 0;

		for (int i = 0; i < height.size(); i++) {
			if (height[i] < v) {
				continue;
			}
			else {
				v = height[i];
			}
			for (int j = i + 1; j < height.size(); j++) {
				int temp = (j - i) * (height[i] > height[j] ? height[j] : height[i]);
				if (temp > max) {
					max = temp;
					left = i;
					right = j;
				}
			}
		}
		std::cout << left << ", " << right << " = " << max << "\n";
		return max;
	}
};

int main() {

	Solution s;
	//int lines[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	//int lines[] = {76, 155, 15, 188, 180, 154, 84, 34, 187, 142, 22, 5, 27, 183, 111, 128, 50, 58, 2, 112, 179, 2, 100, 111, 115, 76, 134, 120, 118, 103, 31, 146, 58, 198, 134, 38, 104, 170, 25, 92, 112, 199, 49, 140, 135, 160, 20, 185, 171, 23, 98, 150, 177, 198, 61, 92, 26, 147, 164, 144, 51, 196, 42, 109, 194, 177, 100, 99, 99, 125, 143, 12, 76, 192, 152, 11, 152, 124, 197, 123, 147, 95, 73, 124, 45, 86, 168, 24, 34, 133, 120, 85, 81, 163, 146, 75, 92, 198, 126, 191};
	int lines[] = { 136,114,104,156,183,152,66,189,116,94,90,58,10,131,67,85,183,174,174,135,88,79,19,0,15,28,96,95,35,174,38,171,88,142,80,24,95,146,13,163,192,103,21,154,187,40,40,122,167,166,58,7,46,77,7,13,58,56,109,93,182,99,17,23,194,97,47,89,195,12,4,188,68,26,142,7,18,134,129,185,101,187,144,99,17,104,112,75,160,173,120,142,73,89,165,67,138,164,108,134 };
	//int lines[] = { 50, 50 };
	vector<int> v(lines, lines + sizeof(lines) / sizeof(int));
	//::cout << s.maxArea(v) << "\n";
	std::cout << s.test1(v) << "\n";
	std::cout << s.test2(v) << "\n";
	//cout << lines[4] << ", " << lines[97] << "\n";
	//cout << lines[0] << ", " << lines[99] << "\n";
	/*
	bool(*fn_pt)(int, int) = fncomp;
	multimap<int, int, bool(*)(int, int)> m(fn_pt);

	for (int i = 0; i < 9; i++) {
		m.insert(pair<int, int>(lines[i], i));
	}
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first << ", " << it->second << "\n";
	}
	*/
	getchar();
}