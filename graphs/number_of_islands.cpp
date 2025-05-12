#include"../stdc++.h"

using namespace std;

vector<pair<int, int>> directions = {{-1, 0} , {1,0}, {0,1}, {0,-1}};

void bfs( vector<string>& vec , int row , int colm ) {
    queue<pair<int, int>> q;
    q.push({row, colm});
    pair<int, int> index;
    while(!q.empty()) {
        index = q.front();
        q.pop();
        vec[index.first][index.second] = '.';
        for (auto p: directions){
            if (((p.first + index.first) >= 0) && ((p.first + index.first) < vec.size()) &&
                ((p.second + index.second) >= 0) && ((p.second + index.second) < vec[0].size()) &&
                (vec[p.first + index.first][p.second + index.second] == '1')){
                    q.push({p.first + index.first, p.second + index.second});
                }
        }
    }

}

int number_of_islands( vector<string> vec) {
    
    int result = 0;

    for(int i = 0; i < vec.size() ; i ++){
        for (int j= 0; j < vec[0].length(); j++) {
            if (vec[i][j] == '1') {
                bfs(vec, i, j);
                result++;
            }
        }
    }

    return result;

}

int main() {
    vector<string> vec = {
            string("11001"),
            string("11001"),
            string("00100"),
            string("00011")
        };
    
    int res = number_of_islands(vec);
    
    cout<<"completed";
}