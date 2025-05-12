#include"../stdc++.h"

using namespace std;



bool can_partition_util(vector<int> arr, int index) {
    if (index == arr.size() ) {
        return true;
    }

    int res;
    if ((index+1 < arr.size()) && (arr[index] == arr[index+1])){
        res = can_partition_util(arr, index + 2);
    }

    if ((index + 2 < arr.size()) && (arr[index] == arr[index+1]) && (arr[index +1 ] == arr[index+2]) ){
        res = res || can_partition_util(arr, index + 3);
    }

    if ((index + 2 < arr.size()) && (arr[index + 1] == arr[index] + 1) && (arr[index +2] == arr[index] + 2) ){
        res = res || can_partition_util(arr, index + 3);
    }

    return res;

}

bool can_partition(vector<int> arr) {
    return can_partition_util(arr, 0);
}


int main() {
    vector<int> arr = {4,4,4,5,6};

    bool out = can_partition(arr);
}