#include"../stdc++.h"

using namespace std;

int remove_overlap_intervals(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end());

    int start_interval = intervals[0][0];
    int end_interval = intervals[0][1];
    int count = 0;

    for (int i = 1; i < intervals.size(); i ++) {
        if (intervals[i][0] < end_interval) {
            count++;
            start_interval = intervals[i][0];
            end_interval = min(end_interval, intervals[i][1]);
        } else {
            start_interval = intervals[i][0];
            end_interval =  intervals[i][1];
        }
    }

    return count;
}

int main(){
    vector<vector<int>> intervals = {{1,2},{2,4},{1,4}};

    int res = remove_overlap_intervals(intervals);

}