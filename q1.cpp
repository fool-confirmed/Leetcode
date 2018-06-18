#include <iostream>
#include <vector>


class Solution {
public:
    // 210ms
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int currentIndex = 0;
        while(currentIndex < nums.size()){
            for(int i = currentIndex + 1; i < nums.size() ; i++){
                std::cout << currentIndex << ", " << i << '\n';
                if(nums[currentIndex] + nums[i] == target){
                    std::vector<int> result;
                    result.push_back(currentIndex);
                    result.push_back(i);
                    return result;
                }
            }
            currentIndex ++;
        }
    }

    // 170ms
    std::vector<int> twoSum2(std::vector<int>& nums, int target) {
        std::vector<int> result;
        int startIndex = 0, endIndex = nums.size() - 1;

        for(startIndex = 0; startIndex < nums.size() / 2; startIndex++){
            for(int distance = 1; distance <= endIndex - startIndex; distance++){
                std::cout << "(" << startIndex << ", " << startIndex + distance << "); (" << endIndex - startIndex << ", " << endIndex - startIndex - distance << ")\n";
                if(nums[startIndex] + nums[startIndex + distance] == target){
                    result.push_back(startIndex);
                    result.push_back(startIndex + distance);
                    return result;
                }
                if(nums[endIndex - startIndex] + nums[endIndex - startIndex - distance] == target){
                    result.push_back(endIndex - startIndex - distance);
                    result.push_back(endIndex - startIndex);
                    return result;
                }
            }
        }
    }
};


int main(){

    Solution foo = Solution();

    int inputs[] = {15, 6, 2, 7, 11, 5};
    std::vector<int> para(inputs, inputs + sizeof(inputs) / sizeof(int));
    std::vector<int> output = foo.twoSum2(para, 9);

    for (std::vector<int>::iterator it = output.begin(); it != output.end(); ++it){
        std::cout << ' ' << *it;
    }
    std::cout << '\n';
}