#include"../stdc++.h"

using namespace std;

int longest_increasing_subseq(vector<int> arr){
    unordered_map <int , int> map;
    int res = 0;
    for (int i = 0; i < arr.size(); i++){
        if (map.find(arr[i]-1) == map.end()) {
            map[arr[i]] = 1;
        } else {
            map[arr[i]] = map[arr[i] - 1] + 1;
        }

        res = max(res, map[arr[i]]);
    }

    return res;
}

int main() {
    vector<int> arr = {1, 2, 4, 5, 3, 4, 5};

    int res = longest_increasing_subseq(arr);
}