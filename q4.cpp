#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

/*
static auto x = [](){
// turn off sync
std::ios::sync_with_stdio(false);
// untie in/out streams
std::cin.tie(0);
return 0;
}();
*/
void addSortVector(std::vector<int>& myVector, int value) {
	if (myVector.size() == 0) {
		myVector.insert(myVector.begin(), value);
		return;
	}
	int guard = 0;
	int left = 0, right = myVector.size() - 1, index = right / 2;
	int foo = 0;
	while (guard < 100) {
		guard++;
		std::cout << "left, index, right = " << left << ", " << index << ", " << right << '\n';
		if (value == myVector.at(index)) {
			myVector.insert(myVector.begin() + index, value);
			break;
		}
		else if (value > myVector.at(index)) {
			if (index == myVector.size() - 1) {
				myVector.insert(myVector.end(), value);
				break;
			}
			if (value <= myVector.at(index + 1)) {
				myVector.insert(myVector.begin() + index + 1, value);
				break;
			}
			left = index;
			foo = 1;
		}
		else if (value < myVector.at(index)) {
			if (index == 0) {
				myVector.insert(myVector.begin(), value);
				break;
			}
			if (value >= myVector.at(index - 1)) {
				myVector.insert(myVector.begin() + index, value);
				break;
			}
			right = index;
			foo = 0;
		}

		index = left + (right - left) / 2 + foo;

	}
	std::cout << "guard = " << guard << '\n';
}

int addSortVectorAgain(std::vector<int>& myVector, int value, int i_start, int i_end) {
	if (myVector.size() == 0) {
		myVector.insert(myVector.begin(), value);
		return 0;
	}
	int guard = 0;
	int left = i_start, right = i_end, index = right / 2;
	int foo = 0;
	while (guard < 100) {
		guard++;
		std::cout << "left, index, right = " << left << ", " << index << ", " << right << '\n';
		if (value == myVector.at(index)) {
			myVector.insert(myVector.begin() + index, value);
			return index;
		}
		else if (value > myVector.at(index)) {
			if (index == myVector.size() - 1) {
				myVector.insert(myVector.end(), value);
				return myVector.size();
			}
			if (value <= myVector.at(index + 1)) {
				myVector.insert(myVector.begin() + index + 1, value);
				return index;
			}
			left = index;
			foo = 1;
		}
		else if (value < myVector.at(index)) {
			if (index == 0) {
				myVector.insert(myVector.begin(), value);
				return 0;
			}
			if (value >= myVector.at(index - 1)) {
				myVector.insert(myVector.begin() + index, value);
				return index;
			}
			right = index;
			foo = 0;
		}

		index = left + (right - left) / 2 + foo;

	}
	std::cout << "guard = " << guard << '\n';
}

class Solution {
public:
	double findMedianSortedArrays_1(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::vector<int> all;
		double media;

		all.reserve(nums1.size() + nums2.size());
		all.insert(all.end(), nums1.begin(), nums1.end());
		all.insert(all.end(), nums2.begin(), nums2.end());

		std::sort(all.begin(), all.end());

		if (all.size() % 2 == 0) {
			media = (all.at(all.size() / 2) + all.at(all.size() / 2 - 1)) / 2.0;
		}
		else {
			media = all.at(all.size() / 2);
		}
		return media;

	}

	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

		double media;
		int i_start = 0;
		for (std::vector<int>::iterator it = nums2.begin(); it != nums2.end(); it++) {
			//addSortVector(nums1, *it);
			i_start = addSortVectorAgain(nums1, *it, i_start, nums1.size() - 1);
			std::cout << "start from " << i_start << "\n";
		}

		if (nums1.size() % 2 == 0) {
			media = (nums1.at(nums1.size() / 2) + nums1.at(nums1.size() / 2 - 1)) / 2.0;
		}
		else {
			media = nums1.at(nums1.size() / 2);
		}
		return media;

	}
};

void printVector(std::vector<int> v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << '\n';
}

int main() {

	std::vector<int> nums1 = { 87,31,18,55,98,57,61,93,30,31,21,51,54,40,24 };
	std::vector<int> nums2 = { 42,68,35,1,70,25,79,59,63,65 };

	std::sort(nums1.begin(), nums1.end());
	std::sort(nums2.begin(), nums2.end());

	printVector(nums1);
	printVector(nums2);

	Solution s;
	std::cout << "M = " << s.findMedianSortedArrays(nums1, nums2) << '\n';
	printVector(nums1);
	/*
	addSortVector(nums1, 599);
	printVector(nums1);

	srand(627);
	for (int i = 0; i < 15; i++) {
		std::cout << rand() % 100 + 1 << ",";
	}
	*/
	getchar();
}
