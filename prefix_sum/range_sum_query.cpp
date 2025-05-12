#include"../stdc++.h"

using namespace std;

vector<vector<int>> prefix_matrix(vector<vector<int>> matrix){

    vector<vector<int>> num_matrix(matrix.size(), vector<int>(matrix[0].size(), 0));
    int row_prefix_sum = 0;
    for (int row = 0; row < matrix.size(); row ++){
        row_prefix_sum = 0;
        for (int col = 0; col< matrix[0].size(); col++)
        {   row_prefix_sum = row_prefix_sum + matrix[row][col];
            num_matrix [row][col] =  row_prefix_sum + ((row - 1) >= 0 ? num_matrix[row-1][col] : 0);
        }
    }

    return num_matrix;

} 

int calculate_area(vector<vector<int>> num_martix, int row1, int col1, int row2, int col2) {

    int area = num_martix[row2][col2] - ((col1 - 1) >= 0 ? num_martix[row2][col1-1] : 0) - ((row1 - 1) >= 0 ? num_martix[row1-1][col2] : 0) + 
        ((((row1 - 1) >= 0) && ((col1 - 1) >= 0)) ? num_martix[row1 - 1][col1-1] : 0);

    return area;
}


int main(){

    vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};

    vector<vector<int>> num_martix = prefix_matrix(matrix);

    int area = calculate_area(num_martix, 2,1,4,3);

}