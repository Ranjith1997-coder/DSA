#include"../stdc++.h"

using namespace std;


vector<int> find_k_closest_elements(vector<int> arr, int k , int x){
    int l = 0;
    int r = arr.size() -1;

    while(r-l+1 > k){
        if ((abs(arr[l] - x) > abs(arr[r] - x))) {
            l++;
        } else {
            r--;
        }
    }

    return vector<int>(arr.begin() + l, arr.begin() + r + 1);

}

int main(){

    vector<int> arr = {1,1,2,3,4,5};

    int k = 4;
    int x = -1;

    vector<int> res = find_k_closest_elements(arr, k , x);
}