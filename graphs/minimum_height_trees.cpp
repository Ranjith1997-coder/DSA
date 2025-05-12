#include"../stdc++.h"

using namespace std;

vector<int> min_height_edge(vector<vector<int>> edges, int n){

    unordered_map<int, vector<int>> graph;

    vector<int> indegree(n, 0);

    for (auto edge: edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
        indegree[edge[0]]++;
        indegree[edge[1]]++;
    }

    queue<int> q;

    for(int i = 0; i < n; i ++){
        if (indegree[i] == 1){
            q.push(i);
        }
    }

    int node;
    vector<int> result;
    int size ;

    while(!q.empty()) {
        if (n <= 2) {
            while(!q.empty()) {
                node = q.front();
                q.pop();
                result.push_back(node);
            }
        }
        size = q.size();
        for (int i = 0; i < size; i++) {
            node = q.front();
            q.pop();
            indegree[node]--;
            for (auto adj: graph[node]) {
                indegree[adj]--;
                if (indegree[adj] == 1){
                    q.push(adj);
                }
            }
            n--;
        }
    }

    return result;

}

int main() {
    int n =4;
    vector<vector<int>> edges = {{{1,0},{1,2},{1,3}}};

    vector<int> res = min_height_edge(edges, n);
}