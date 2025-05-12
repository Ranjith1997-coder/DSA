#include"../stdc++.h"

using namespace std;

int global_target = 0;

bool canPartitionKSubsets_util(vector<int> nums, int k , vector<bool>& added , int target) {

    if (k == 0) {
        return true;
    }
    if (target == 0) {
        return canPartitionKSubsets_util(nums, k-1, added , global_target);
    }
    
    for (int i = 0; i < nums.size(); i ++) {
        if (added[i] == true) {
            continue;
        }
        if (target - nums[i] < 0) {
            continue;
        }
        added[i] = true;

        if (canPartitionKSubsets_util(nums, k , added, target - nums[i])) {
            return true;
        }
        added[i] = false;
    }

    return false;

}

bool canPartitionKSubsets(vector<int>nums , int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % k  != 0) {
        return false;
    }
    int target = sum / k;
    global_target = target;
    vector<bool> added(nums.size(), false);

    return canPartitionKSubsets_util(nums , k , added, target );

}

int main() {
    vector<int> nums = {4,3,2,3,5,2,1};
    // vector<int> nums = {1,2,3,4};
    int k = 4;

    bool res = false;
    res = canPartitionKSubsets(nums, k);
}