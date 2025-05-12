#include "../stdc++.h"

using namespace std;


bool dfs(unordered_map<int, vector<int>> adj_list,int node, unordered_set<int>& cycle_detect, 
    unordered_set<int>& visited, vector<int>& output) {

        if (cycle_detect.count(node)) {
            return false;
        }

        if (visited.count(node)) {
            return true;
        }

        cycle_detect.insert(node);
        if (adj_list.find(node) != adj_list.end()) {
            for (auto neigh : adj_list[node]){
                if (!dfs(adj_list, neigh, cycle_detect, visited, output)){
                    return false;
                }
            }
        }
        visited.insert(node);
        output.push_back(node);
        cycle_detect.erase(node);
        return true;
    }

vector<int> topological_sort(int num_of_courses, vector<vector<int>> preq_list){
    unordered_map<int, vector<int>> adj_list;

    for (auto preq : preq_list) {
        adj_list[preq[0]].push_back(preq[1]);
    }

    unordered_set<int> cycle_detect;
    unordered_set<int> visited;
    vector<int> output;

    for (auto node : adj_list) {
        if (!dfs(adj_list, node.first, cycle_detect, visited, output)){
            return {};
        }
    }
    
    return output;
    
}


int main() {
    int num_of_courses = 4;
    vector<vector<int>> preq = {{1,0}, {2,0}, {0,1}, {3,2}};

    vector<int> res = topological_sort(num_of_courses, preq);

    cout<<"completed";
}