#include"../stdc++.h"

using namespace std;



vector<int> memo;

int house_robber_util(vector<int> nums , int index) {
    if (index >= nums.size()) {
        return 0;
    }

    if (memo[index] != -1) {
        return memo[index];
    }

    memo[index] = max(nums[index] + house_robber_util(nums, index + 2) , house_robber_util(nums, index + 1));

    return memo[index];

}

int house_robber(vector<int> nums) {
    memo = vector<int> (nums.size(), -1);

    return house_robber_util(nums , 0);

}

int main() {

    vector<int>nums = {1,1,3,3};

    int res = house_robber(nums);

}