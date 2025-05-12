#include"../stdc++.h"

using namespace std;

bool part_equal_subset_util(vector<int> nums, int index , int target) {

    

    if(target < 0){
        return false;
    }

    if (target == 0){
        return true;
    }

    if(index >= nums.size()){
        return false;
    }

    return part_equal_subset_util(nums, index+1 , target - nums[index]) | part_equal_subset_util(nums, index+1 , target);

}

bool part_equal_subset(vector<int> nums) {

    bool out = false;
    vector<int> subset;
    int target = 0;
    for (int i = 0; i < nums.size(); i++){
        target += nums[i];
    }

    if (target%2 != 0) {
        return false;
    }
    target = target/2;

    return part_equal_subset_util(nums, 0, target);

}

int main() {
    vector<int> nums = {1,2,3,4, 5};

    bool res = part_equal_subset(nums);

}