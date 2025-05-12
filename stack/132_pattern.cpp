#include"../stdc++.h"

using namespace std;


bool is_132_pattern(vector<int> nums) {
    vector<int> min_vector(nums.size());
    stack<int> s;
    for (int i = 0; i < nums.size(); i ++){
        if (i == 0){
            min_vector[0] = i;
        } else {
            if (nums[i] < nums[min_vector[i-1]]) {
                min_vector[i] = i;
            } else {
                min_vector[i] = i-1;
            }
        }

        while((!s.empty()) && (nums[i] > s.top())) {
            s.pop();
        }

        if (nums[min_vector[i]] < nums[i]) {
            return true;
        }

        s.push(i);

    }

    return false;

}


int main() {
    vector<int> nums = {3,1,4,2};

    bool res = is_132_pattern(nums);
}