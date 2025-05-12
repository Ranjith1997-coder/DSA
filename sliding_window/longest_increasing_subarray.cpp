#include"../stdc++.h"

using namespace std;

int longest_increasing_subarray(vector<int> arr){

    int count = 1;
    int res = INT_MIN;
    bool can_change = true;
    for (int i = 1; i < arr.size(); i ++){
        if (arr[i] > arr[i-1]) {
            count++;
        } else {
            if (can_change == true) {
                count++;
                i++;
                if ((i < arr.size()) && (arr[i] > arr[i-2])) {
                    count++;
                } 
                can_change = false;
            } else {
                res = max(res, count);
                count = 1;
                can_change = true;
            }
            
        }
    }
    res = max(res, count);

    return res;

}

int main() {
    vector<int> arr = {0 ,7, 3, 10, 2, 4, 6, 8, 0, 9, 10, 11};

    int res = longest_increasing_subarray(arr);
}