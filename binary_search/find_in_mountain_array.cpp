#include"../stdc++.h"

using namespace std;

int find_peak(vector<int> arr){
    if (arr[0] > arr[1]) {
        return 0;
    }

    int l = 0;
    int r = arr.size() -1;
    int mid = 0;

    while(l <= r) {
        mid = (l + r) / 2;

        if ((arr[mid] > arr[mid-1]) && (arr[mid] > arr[mid+1])) {
            return mid;
        }

        if (arr[mid] < arr[mid+1]) {
            l = mid+1;
        }else {
            r = mid;
        }

    }

    return mid;
}

int find_in_array(vector<int> arr, int tar){

    int peak_index = find_peak(arr);

    return peak_index;

}

int main(){
    vector<int> arr = {1,2,3,4,5,3,1};
    int tar = 3;

    int index = find_in_array(arr, tar);
}