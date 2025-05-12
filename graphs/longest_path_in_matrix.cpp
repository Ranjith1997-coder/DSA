#include"../stdc++.h"

using namespace std;

vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1},  {0,-1}};

vector<vector<int>> memo;

int dfs(vector<vector<int>> matrix, int prev_val, int i , int j){
    if ((i < 0) || (i >= matrix.size()) || (j < 0) || (j >= matrix[i].size()) || (matrix[i][j] <= prev_val)) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j] ;
    }
    for (auto dir: directions) {
        memo[i][j] = max(memo[i][j], 1 + dfs(matrix, matrix[i][j], i + dir.first, j + dir.second));
    }

    return memo[i][j];
}

int longest_path_in_matrix(vector<vector<int>> matrix){

    int res = 0;
    int prev_val = -1;
    memo = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));
    for(int i = 0; i < matrix.size(); i ++){
        for(int j = 0; j < matrix[i].size(); j++){
            res = max(res, dfs(matrix, prev_val, i , j));
        }
    }

    return res;

}

int main(){

    vector<vector<int>> matrix  = {{9,9,4},{6,6,8},{2,1,1}};

    int out = longest_path_in_matrix(matrix);
}