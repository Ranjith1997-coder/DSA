#include"../stdc++.h"

using namespace std;

void longest_inc_sub_util(vector<int> nums, int index, vector<int> subseq, int& output) {
    if (index >= nums.size() - 1){
        if (subseq.size() > output) {
            output = subseq.size();
        }
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        if (subseq.empty()){
            subseq.push_back(nums[index]);
            longest_inc_sub_util(nums, i + 1, subseq, output);
            subseq.pop_back();
        } else {
            if(subseq.back() < nums[i]) {
                subseq.push_back(nums[i]);
                longest_inc_sub_util(nums, i + 1, subseq, output);
                subseq.pop_back();
            }
        }

    }

    return;

}

int longest_increasing_subsequence(vector<int> nums){
    int output = 0;
    vector<int> subseq;
    longest_inc_sub_util(nums, 0, subseq, output);

    return output;
}


int main() {
    vector<int> nums = {1,4,2,3,3,7};

    int res = longest_increasing_subsequence(nums);

}