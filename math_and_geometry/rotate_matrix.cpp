#include"../stdc++.h"

using namespace std;


int swap(int& t1, int& t2) {
    int tmp = t1;
     t1 = t2;
     t2 = tmp;

}

void rotate_matrix(vector<vector<int>>& matrix) {

    int l = 0;
    int r = matrix[0].size() -1;
    int t = 0;
    int b = matrix.size() -1;
    int tmp_var = 0;
    while(l <= r) {
        t = l;
        b = r;
        for (int i = 0; i < r - l ; i++) {
            tmp_var = matrix[t][l + i];
            swap(tmp_var, matrix[t + i][r]);
            swap(tmp_var, matrix[b][r - i]);
            swap(tmp_var, matrix[b - i][l]);
            swap(tmp_var, matrix[t][l + i]);

        }   
        l = l+1;
        r = r-1;
    }

}

int main() {
    vector<vector<int>> matrix = {{1,2,3},
        {4,5,6},
        {7,8,9}};

    rotate_matrix(matrix);
}