#include"../stdc++.h"

using namespace std;


vector<int> sprial_matrix(vector<vector<int>>& matrix) {

    int l = 0;
    int r = matrix[0].size() - 1;
    int t = 0;
    int b = matrix.size() - 1 ;
    vector<int> res ;

    while((l <= r) && (t <= b)) {
        for (int i = l ; i <= r; i++) {
            res.push_back(matrix[t][i]);
        }
        t++;

        for (int i = t ; i <= b; i++) {
            res.push_back(matrix[i][r]);
        }
        r--;

        if (!((l <= r) && ( t <= b))) {
            break;
        }

        for (int i = r ; i >= l; i--) {
            res.push_back(matrix[b][i]);
        }
        b--;

        for (int i = b ; i >= t; i--) {
            res.push_back(matrix[i][l]);
        }
        l++;

    }
    return res;

}

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    vector<int> res = sprial_matrix(matrix);
}