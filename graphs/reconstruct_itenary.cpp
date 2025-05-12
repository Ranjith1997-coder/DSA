#include"../stdc++.h"

using namespace std;


bool reconstruct_itenary_util(unordered_map<string, vector<string>> &tickets, string start_station, vector<string>& res,
                                int stations_covered) {

    if ((tickets[start_station].empty())){
        if (tickets.size() == stations_covered) {
            return true;
        } else {
            return false;
        }
    }

    string new_station ;
                                
    for(int i = 0; i< tickets[start_station].size(); i ++) {
        new_station = tickets[start_station][i];
        res.push_back(new_station);
        tickets[start_station].erase(tickets[start_station].begin() + i);
        if (reconstruct_itenary_util(tickets, new_station, res, stations_covered + 1)){
            return true;
        }
        tickets[start_station].insert( tickets[start_station].begin() + i, new_station);
        res.pop_back();
    }

    return false;

}

vector<string> reconstruct_itenary(vector<pair<string, string>> tickets){

    unordered_map<string, vector<string>> routes_map;

    for (auto ticket : tickets){
        routes_map[ticket.first].push_back(ticket.second);
    }

    for (auto route: routes_map){
        sort(route.second.begin(), route.second.end());
    }

    vector<string> res = {"JFK"};
    reconstruct_itenary_util(routes_map, "JFK", res, 1);

    return res;

}


int main(){
    vector<pair<string, string>> tickets = {{"BUF","HOU"},{"HOU","SEA"},{"JFK","BUF"}};

    vector<string> output = reconstruct_itenary(tickets);
}