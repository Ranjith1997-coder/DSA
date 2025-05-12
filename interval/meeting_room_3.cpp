#include"../stdc++.h"

using namespace std;

int mostBooked(vector<vector<int>>& meetings, int rooms){

    vector<int> meetings_count(rooms , 0);

    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> used_rooms;
    priority_queue<int, vector<int>, greater<int>> unused_rooms;
    
    for (int i =0; i < rooms; i ++){
        unused_rooms.push(i);
    }

    // vector<int> start_time;
    // vector<int> end_time;

    // for (int i = 0; i < meetings.size(); i++){
    //     start_time.push_back(meetings[i][0]);
    //     end_time.push_back(meetings[i][1]);
    // }

    // sort(start_time.begin(), start_time.end());
    // sort(end_time.begin(), end_time.end());
    // int selected_room;
    // int start_index = 0;
    // int end_index = 0;

    // while(end_index < meetings.size()){
    //     if (start_index < end_index) {
    //         if (unused_rooms.size()) {
    //             selected_room =  unused_rooms.top();
    //             meetings_count[selected_room]++;
    //             unused_rooms.pop();
    //             used_rooms.push({meeting[1] + time, selected_room});
    //         } 
    //     }
    // }

    sort(meetings.begin(), meetings.end());
    int selected_room;
    int index = 0;
    int time = meetings[0][0];
    int end_time;
    while (index < meetings.size()){
        if (unused_rooms.size()) {
            selected_room =  unused_rooms.top();
            meetings_count[selected_room]++;
            unused_rooms.pop();
            if (time == meetings[index][0]) {
                time = meetings[index][0];
                end_time = meetings[index][1];
            } else if (time < meetings[index][0]) {
                time = meetings[index][0];
                end_time = time + meetings[index][1] - meetings[index][0];
            } else {
                end_time = time + meetings[index][1] - meetings[index][0];
            }
            used_rooms.push({end_time, selected_room});
            index++;
        } else {
            pair<int,int> used_room = used_rooms.top();
            used_rooms.pop();
            unused_rooms.push(used_room.second);
            time = used_room.first;
        }
    }



    return 0;


}

int main(){
    vector<vector<int>> meetings = {{0,10},{1,5},{2,7},{3,4}};

    int rooms = 2;

    int max_meeting_room = mostBooked(meetings, rooms);

}