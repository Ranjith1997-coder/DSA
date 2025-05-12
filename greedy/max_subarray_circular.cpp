#include"../stdc++.h"

using namespace std;

int max_subarray_circular(vector<int> nums){
    int total_sum = accumulate(nums.begin(), nums.end(), 0);

    int total_max = nums[0];
    int total_min = nums[0];
    int curr_max = 0;
    int curr_min = 0;

    for (int i = 0; i < nums.size(); i++) {
        curr_max = max( curr_max + nums[i],nums[i]);
        curr_min = max( curr_max + nums[i],nums[i]);
        total_max = max(curr_max, total_max);
        total_min = min(curr_min , total_min);

    }

    return (total_max > 0) ? max(total_max , (total_sum - total_min)) : total_max;
}

int main() {
    vector<int> nums = {-3,-2,-3};

    int output = max_subarray_circular(nums);
}