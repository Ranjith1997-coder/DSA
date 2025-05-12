#include"../stdc++.h"

using namespace std;

int minMeetingRooms(vector<vector<int>> meeting_intervals){

    vector<int> start_time;
    vector<int> end_time;

    for (int i = 0; i< meeting_intervals.size(); i++){
        start_time.push_back(meeting_intervals[i][0]);
        end_time.push_back(meeting_intervals[i][1]);
    }

    sort(start_time.begin(), start_time.end());
    sort(end_time.begin(), end_time.end());

    int start_index = 0;
    int end_index = 0;
    int rooms = 0;
    int res = 0;

    while(start_index < meeting_intervals.size()) {
        if (start_time[start_index] < end_time[end_index]) {
            rooms++;
            start_index++;
        } else {
            rooms--;
            end_index++;
        }

        res = max(res, rooms);

    }

    return res;

}

int main(){
    vector<vector<int>> meeting_intervals = {{0,40},{5,10},{15,20}};

    int res = minMeetingRooms(meeting_intervals);
}