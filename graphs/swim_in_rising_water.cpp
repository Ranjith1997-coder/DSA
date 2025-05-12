#include "../stdc++.h"

using namespace std;


vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {-1,1}};


int swim_in_raising_water_util(vector<vector<int>> matrix , int i , int j, vector<vector<bool>> visited) {
    if ((i == matrix.size()-1) && (j == matrix[0].size() - 1)){
        return matrix[i][j];
    }

    int result = INT_MAX;
    int ret = 0;

    visited[i][j] = true;
    for (auto dir : directions) {
        if ((i+ dir.first < matrix.size()) && (j+ dir.second < matrix[0].size()) && (!visited[i+ dir.first][j+dir.second])) {
            ret = max(swim_in_raising_water_util(matrix, i+ dir.first, j+ dir.second, visited) , matrix[i][j]);
            result = min(ret, result);
        }
        
    }
    visited[i][j] = false;

    return result;

}

int swim_in_raising_water(vector<vector<int>> matrix){

    // vector<vector<bool>> v = vector<vector<bool>>(matrix.size(), vector<bool>(matrix[0].size(), 0));

    // return swim_in_raising_water_util(matrix, 0, 0, v);

    /* using dikstra*/ 

    vector<vector<bool>> visited = vector<vector<bool>>(matrix.size(), vector<bool>(matrix[0].size(), 0));

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    pq.push({matrix[0][0], 0, 0});

    vector<int> tmp_vec;
    int dist, x, y;

    while(!pq.empty()) {
        tmp_vec = pq.top();
        pq.pop();

        dist = tmp_vec[0];
        x = tmp_vec[1];
        y =  tmp_vec[2];

        visited[x][y] = true;

        if ((x == matrix.size() - 1) && (y == matrix[0].size() - 1)) {
            return dist;
        }

        for (auto dir: directions) {
            if (((x + dir.first < matrix.size() ) && (x + dir.first >= 0 )) && 
                ((y + dir.second < matrix[0].size() ) && (y + dir.second >= 0 )) && 
                (!visited[x + dir.first][y + dir.second])){
                    pq.push({max(dist, matrix[x + dir.first][y + dir.second]), x + dir.first, y + dir.second});
                }
        }

    }
    
    return matrix.size() * matrix.size();

}

int main() {

    vector<vector<int>> matrix = {
        {0,1,2,10},
        {9,14,4,13},
        {12,3,8,15},
        {11,5,7,6}
      };

    int out = swim_in_raising_water(matrix);
}