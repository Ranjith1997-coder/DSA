#include"../stdc++.h"

using namespace std;


void dfs(int node, unordered_map<int,vector<int>> adj_list, 
        vector<bool>& visited, vector<int>& dist, 
        vector<int>& low, vector<vector<int>>& gcc_final, stack<int> &s, int time) {

    visited[node] = true;
    dist[node] = time;
    low[node] = time;
    s.push(node);

    for (auto adj : adj_list[node]){
        if (!visited[adj]) {
            dfs(adj, adj_list, visited,  dist, low, gcc_final, s, time+1);
            low[node] = min(low[node], low[adj]);
        } else {
            low[node] = min(low[node], dist[adj]);
        }
    }

    if (dist[node] == low[node]) {
        vector<int> gcc;
        while(s.top() != node) {
            gcc.push_back(s.top());
            s.pop();
        }
        gcc.push_back(s.top());
        s.pop();
        gcc_final.push_back(gcc);
    }

}

vector<vector<int>> findSCC(int vertex , vector<vector<int>> edges) {

    unordered_map<int , vector<int>> adj_list;

    for (auto edge: edges) {
        adj_list[edge[0]].push_back(edge[1]);
    }

    vector<bool> visited(vertex +1 , 0);
    vector<int> dist(vertex +1, -1);
    vector<int> low(vertex +1, -1);
    vector<vector<int>> gcc; 
    stack<int> s;

    for (int i = 1; i <= vertex ; i ++){
        if (!visited[i]) {
            dfs(i, adj_list, visited,  dist, low, gcc , s, 0);
        }
    }

    return gcc;

}


int main() {

    int V = 5;
    vector<vector<int> > edges{
        { 1, 3 }, { 1, 4 }, { 2, 1 }, { 3, 2 }, { 4, 5 }
    };
    vector<vector<int>> ans = findSCC(V, edges);
}