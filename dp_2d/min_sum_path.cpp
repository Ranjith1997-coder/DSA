#include"../stdc++.h"

using namespace std;



int min_sum(vector<vector<int>> grid, int i , int j, int sum) {
    if ((i == grid.size() -1 ) && (j == grid[0].size() - 1)) {
        return sum + grid[i][j];
    }

    if ((i >= grid.size() ) || (j >= grid[0].size())){
        return 99999;
    }

    return min(min_sum(grid, i + 1, j, sum + grid[i][j]) , min_sum(grid, i , j + 1, sum + grid[i][j]));

}

int min_sum(vector<vector<int>> grid) {

    int output = min_sum(grid, 0, 0, 0);

    return output;
}

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};

    int output = min_sum(grid);

}