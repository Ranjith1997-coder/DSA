#include"../stdc++.h"

using namespace std;

vector<vector<int>> memo;

int unique_paths(int m, int n) {
    if ((m == 1) && (n == 1)) {
        return 1;
    }

    if ((m < 1) || (n < 1)) {
        return 0;
    }

    if (memo[m-1][n-1] != -1){
        return memo[m-1][n-1];
    }

    memo[m-1][n-1] = unique_paths(m-1, n) + unique_paths(m, n-1);
    return memo[m-1][n-1];

}

int main() {
    int m = 3, n = 6;

    memo = vector<vector<int>>(m, vector<int>(n, -1));

    int output = unique_paths(m , n);
}