#include "../stdc++.h"

using namespace std;


int max_subarray(vector<int> nums) {
    int sum = 0;
    int result = 0;

    for (int i = 0; i < nums.size() ; i ++) {
        sum += nums[i];
        if (sum < 0) {
            sum = 0;
        } else {
            result = max(sum , result);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {2,-3,4,-2,2,1,-1,4};

    int output = max_subarray(nums);
}