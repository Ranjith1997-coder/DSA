#include"../stdc++.h"

using namespace std;

int subarray_sums_equals_k(vector<int> nums, int k){
    unordered_map<int,int> pre_sum_count;
    int sum = 0;
    pre_sum_count[0] = 1;
    int count = 0;
    for(int i = 0; i< nums.size(); i ++){
        sum += nums[i];

        if (pre_sum_count.find(sum - k) != pre_sum_count.end()){
            count += pre_sum_count[sum - k];
        }
        pre_sum_count[sum]++; 
    }
    return count;
}

int main() {
    vector<int> nums = {1,1,1};
    int k =2;

    int res = subarray_sums_equals_k(nums, k);
}