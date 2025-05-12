#include"../stdc++.h"

using namespace std;

int min_size_sub_array(vector<int> nums, int target){

    int min_size = INT_MAX;
    int start_index  = 0;
    int sum = 0;
    int end_index = 0;
    while(end_index < nums.size()) {

        sum += nums[end_index];
        while (sum >= target) {
            min_size = min(end_index-start_index+1, min_size);
            sum -= nums[start_index];
            start_index++;  
        }
        end_index++;
    
    }

    return min_size;
        
}

int main(){

    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    int size = min_size_sub_array(nums, target);

}