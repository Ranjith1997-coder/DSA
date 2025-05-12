#include"../stdc++.h"

using namespace std;


bool is_queen_safe(vector<string> chess_board, int row, int colm) {
    for (int x = colm; x >= 0; x--) {
        if (chess_board[row][x] == 'Q') {
            return false;
        }
    }

    for (int x = row, y = colm ; x < chess_board.size() && y >= 0; x++ , y--) {
        if (chess_board[x][y] == 'Q') {
            return false;
        }
    }

    for (int x = row, y = colm ; x >= 0 && y >= 0; x-- , y--) {
        if (chess_board[x][y] == 'Q') {
            return false;
        }
    }

    return true;
}

void solveNQueens_util(vector<string>& chess_board,int n,  int colm_index, vector<vector<string>>& res) {
    if (colm_index == n) {
        res.push_back(chess_board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (is_queen_safe(chess_board, row, colm_index)) {
            chess_board[row][colm_index] = 'Q';
            solveNQueens_util(chess_board, n, colm_index + 1, res);
            chess_board[row][colm_index] = '.';
        }
    }

}

vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> res ;
    vector<string> chess_board (n, string(n, '.') );
    solveNQueens_util(chess_board, n, 0, res);

    return res;

}


int main() {

    int n = 4;

    vector<vector<string>> res = solveNQueens(n);
    cout<<"completed";

}