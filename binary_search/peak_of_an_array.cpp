#include"../stdc++.h"

using namespace std;

int find_peak(vector<int> arr) {
    int l =0;
    int r = arr.size() -1;

    int mid = 0;

    while(l < r){

        mid = (l+r)/2;

        if ((arr[mid] > arr[mid+1]) && (arr[mid] > arr[mid-1])){
            return mid;
        }

        if (arr[mid] <= arr[mid+1]) {
            l = mid+1;
        } else {
            r = mid;
        }
    }

    return l;

}

int main() {
    vector<int> arr = {1, 2, 8, 4, 3, 2, 1};
    
    int res = find_peak(arr);
    
}