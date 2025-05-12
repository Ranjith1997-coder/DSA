#include"../stdc++.h"

using namespace std;

vector<int>  topological_sorting_using_Kahns(int vertex, vector<pair<int, int>> edges) {
    map<int , vector<int>> adj_list;
    vector<int> indegree(vertex, 0);

    for (auto edge: edges) {
        adj_list[edge.first].push_back(edge.second);
        indegree[edge.second]++;
    }

    queue<int> zero_indegree;
    vector<int> result;

    for (int i =0; i < vertex; i ++) {
        if (indegree[i] == 0) {
            zero_indegree.push(i);
        }
    }
    int node;
    int visited = 0;
    while (!zero_indegree.empty()) {
        node = zero_indegree.front();

        zero_indegree.pop();
        for (auto neigh: adj_list[node]) {
            indegree[neigh]--;
            if (!indegree[neigh]) {
                zero_indegree.push(neigh);
            }
        }
        visited++;
        result.push_back(node);

    }

    return result;
}

int main() {
    int vertex = 6;
    vector<pair<int, int>> edges = {{2,3}, {3,1}, {4,0}, {4,1}, {5,0}, {5,2}};

    vector<int> result = topological_sorting_using_Kahns(vertex, edges);

}