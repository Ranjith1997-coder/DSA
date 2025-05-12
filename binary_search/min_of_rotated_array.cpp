#include"../stdc++.h"

using namespace std;

int min_in_rotated_array(vector<int> array) {

    int left , right , mid;

    left = 0;
    right = array.size() -1;

    while (left <= right) {
        mid = left + (right -left) /2;

        if (array[mid] < array[mid -1]) {
            return array[mid];
        }

        if (array[mid] >= array[left]) {
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }

    return array[mid] ;

}

int main() {
    vector<int> list = {7,1,4,5,6};

    int res = min_in_rotated_array(list);
}