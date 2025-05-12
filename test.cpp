#include"./stdc++.h"


using namespace std;

vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};


void dfs(int i, int j, vector<vector<int>> &matrix , vector<vector<bool>> &visited ,int sum,  int& max_sum) {

    if ((i < 0) || (i >= matrix.size()) || (j < 0) || (j >= matrix[0].size()) || (visited[i][j] == true) || (matrix[i][j] == 0)) {
        max_sum = max(sum, max_sum);
        return;
    }

    visited[i][j] = true;
    sum += matrix[i][j];

    for (auto dir: directions){
        dfs(dir.first+ i, dir.second+j, matrix, visited, sum, max_sum);
        
    }

}

int max_sum_matrix(vector<vector<int>>& matrix) {


    int max_sum = 0;
    vector<vector<bool>> visited;
    for (int i = 0; i <matrix.size() ; i ++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            visited = vector<vector<bool>>(matrix.size(), vector<bool>(matrix[0].size() , 0));
            dfs(i, j , matrix, visited, 0, max_sum);
        }
    }

    return max_sum;
    

}
//1,0,5
//2,7,9
//0,1,3

int main() {
    vector<vector<int>> matrix  = {{1,0,5}, {2,7,9} , {0,1,3}};
    
    int max_sum = max_sum_matrix(matrix);
}