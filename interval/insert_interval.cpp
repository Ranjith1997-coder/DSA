#include"../stdc++.h"

using namespace std;

vector<vector<int>> merge_interval(vector<vector<int>>& intervals, vector<int> new_interval){

    vector<vector<int>> res;

    for (int i = 0; i< intervals.size(); i++){
        if (new_interval[0] > intervals[i][1]) {
            res.push_back(intervals[i]);
        } else if (new_interval[1] < intervals[i][0]) {
            res.push_back(new_interval);
            for (int j = i; j < intervals.size(); j++) {
                res.push_back(intervals[j]);
            }
            return res;
        } else {
            new_interval[0] = min(intervals[i][0], new_interval[0]);
            new_interval[1] = max(intervals[i][1], new_interval[1]);
        }
    }
    res.push_back(new_interval);

    return res;

}

int main() {
    vector<vector<int>> intervals = {{1,3},{4,6}};
    vector<int> new_interval = {2,5};

    vector<vector<int>> res = merge_interval(intervals, new_interval);

}