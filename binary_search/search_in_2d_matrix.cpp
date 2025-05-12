#include"../stdc++.h"

using namespace std;

bool search_in_matrix(vector<vector<int>> matrix, int target) {

    int left, right, mid;

    left = 0; 
    right = matrix.size() - 1;

    int row;

    while(left <= right) {
        mid = (left + right) /2;

        if (target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size() - 1]) {
            row = mid;
            break;
        }

        if (target > matrix[mid][0] && target > matrix[mid][matrix[mid].size() - 1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

    }

    left = 0;
    right = matrix[row].size() - 1;

    while(left <= right) {
        mid = (left + right) /2;

        if (target == matrix[row][mid]) {
            return true;
        }

        if (target > matrix[row][mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

    }

    return false;

}

int main(){
    vector<vector<int>> matrix = {{1,2,4,8},{10,11,12,13},{14,20,30,40}};

    int target = 10;

    bool res = search_in_matrix(matrix, target);

}