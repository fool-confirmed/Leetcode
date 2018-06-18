#include <iostream>
#include <vector>


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int currentIndex = 0;
        while(currentIndex < nums.size()){
            for(int i = currentIndex + 1; i < nums.size() ; i++){
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
};


int main(){
    Solution foo = Solution();

    int inputs[] = {7, 2}; //{15, 7, 11, 2};
    std::vector<int> para(inputs, inputs + sizeof(inputs) / sizeof(int));
    std::vector<int> output = foo.twoSum(para, 9);

    for (std::vector<int>::iterator it = output.begin(); it != output.end(); ++it){
        std::cout << ' ' << *it;
    }
    std::cout << '\n';
}