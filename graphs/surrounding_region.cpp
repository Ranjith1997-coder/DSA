#include"../stdc++.h"

using namespace std;

void dfs(vector<vector<char>>& region , int i , int j) {
    if ((i >= region.size()) || ( i < 0) || (j >= region[0].size()) || (j<0)) {
        return;
    }
    if (region[i][j] != '-') {
        return;
    }

    region[i][j] = 'O';

    dfs(region, i+1 , j);
    dfs(region, i-1 , j);
    dfs(region, i , j+1);
    dfs(region, i , j-1);


}

void change_surround_region(vector<vector<char>>& region) {
    for (int i = 0; i < region.size(); i ++){
        for (int j = 0; j< region[0].size() ; j++) {
            if (region[i][j] == 'O') {
                region[i][j] = '-';
            }
        }
    }

    for (int i = 0; i < region.size(); i++) {
        dfs(region, i, 0);
    }

    for (int i = 0; i < region.size(); i++) {
        dfs(region, i, region.size()-1);
    }

    for (int i = 0; i < region.size(); i++) {
        dfs(region, 0, i);
    }

    for (int i = 0; i < region.size(); i++) {
        dfs(region, region.size() - 1, i);
    }


}

int main() {
    vector<vector<char>> region = {{'X', 'O', 'X', 'X', 'X', 'X'}, 
    {'X', 'O', 'X', 'X', 'O', 'X'},
    {'X', 'X', 'X', 'O', 'O', 'X'},
    {'O', 'X', 'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'O', 'X', 'O'},
    {'O', 'O', 'X', 'O', 'O', 'O'}};

    change_surround_region(region);

    cout<<"completed";
}