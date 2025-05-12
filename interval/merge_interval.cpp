#include"../stdc++.h"

using namespace std;

vector<vector<int>> merge_interval(vector<vector<int>>intervals) {
    vector<vector<int>> output;

    output.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++){
        if (intervals[i][0] < output[output.size()-1][1]) {
            output[output.size()-1][0] = min(output[output.size()-1][0], intervals[i][0]);
            output[output.size()-1][1] = max(output[output.size()-1][1], intervals[i][1]);
        } else {
            output.push_back(intervals[i]);
        }
    }

    return output;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{1,5},{6,7}};

    vector<vector<int>> res = merge_interval(intervals);
}