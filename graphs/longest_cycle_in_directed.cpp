#include"../stdc++.h"

using namespace std;


void longest_cycle_graph_util(int index,int length, unordered_map<int, vector<int>> adj_list,vector<int>& visited,
                             vector<bool>& path_visited,  int& max_cycle_length) {
    visited[index] = length;
    path_visited[index] = 1;

    for (auto neigh: adj_list[index]){
        if (!visited[neigh]){
            longest_cycle_graph_util(neigh, length+1, adj_list, visited, path_visited, max_cycle_length);
        } else if ((visited[neigh]) && path_visited[neigh]){
            max_cycle_length = max(max_cycle_length , length - visited[neigh]);
        }
    }

    path_visited[index] = 0;

}

int longest_cycle_graph(vector<int> edges){

    unordered_map<int, vector<int>> adj_list;

    for (int i = 0; i < edges.size(); i++){
        if (edges[i]!=-1)
        adj_list[i].push_back(edges[i]);
    }

    vector<int> visited (edges.size(), 0);
    vector<bool> path_visited (edges.size(), 0);
    int max_cycle_length = -1;

    for (int i =0; i < edges.size(); i ++){
        if (!visited[i]){
            longest_cycle_graph_util(i, 1,  adj_list, visited, path_visited, max_cycle_length);
        }
    }
    
    return max_cycle_length;


}

int main() {
    vector<int> edges = {3,4,0,2,-1,2};

    int res = longest_cycle_graph(edges);
}