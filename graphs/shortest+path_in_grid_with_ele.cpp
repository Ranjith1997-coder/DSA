#include"../stdc++.h"

using namespace std;

int shortest_path(vector<vector<int>> matrix, int k) {

    vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
    queue<vector<int>> q ;

    q.push({0,0,0,k});
    vector<int> index;
    int x, y, res = -1;

    while(!q.empty()) {
        index = q.front();
        x = index[0];
        y = index[1];
        q.pop();
        visited[x][y] = 1;

        if ((x == matrix.size()-1) && (y == matrix[0].size()-1)) {
            return index[2];
        }

        if ((matrix[x][y] == 1) && (index[3] == 0)) {
            continue;
        }

        if ((matrix[x][y] == 1) && (index[3] != 0)) {
            index[3] -= 1;
        }

        if ((x+1 < matrix.size()) && (visited[x+1][y] != 1)) {
            q.push({x+1, y, index[2] + 1, index[3]});
        }
        if ((x-1 >= 0) && (visited[x-1][y] != 1)) {
            q.push({x-1, y, index[2] + 1, index[3]});
        }
        if ((y-1 >= 0) && (visited[x][y-1] != 1)) {
            q.push({x, y-1, index[2] + 1, index[3]});
        }
        if ((y+1 < matrix[0].size()) && (visited[x][y+1] != 1)) {
            q.push({x, y+1, index[2] + 1, index[3]});
        }
        visited[x][y] = 1;

    }

    return -1;

}

int main() {
    vector<vector<int>> matrix = {{0,1,1},{1,1,1},{1,0,0}};

    int k = 1;

    int res = shortest_path(matrix, k);

}