#include"../stdc++.h"

using namespace std;

class DJS {
    public:
        vector<int> parent;
        vector<int> rank;

        DJS(int size) {
            parent.resize(size);
            rank = vector<int>(size, 1);

            for (int i=0; i < size; i ++){
                parent[i] = i;
            }
        }

        int find(int a){
            int x = a;
            while(x != parent[x]) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        bool union_set(int a , int b){
            int p_a = find(a);
            int p_b = find(b);

            if (p_a == p_b) {
                return false;
            }

            if (rank[p_b] >= rank[p_a]) {
                parent[p_a] = parent[p_b];
                rank[p_b] += rank[p_a];
            } else {
                parent[p_b] = parent[p_a];
                rank[p_a] += rank[p_b];
            }

            return true;
        }
};

int main() {
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {4,5}, {4,2}};
    int nodes = 6;
    int res = nodes;
    DJS d(nodes);
    for (auto edge : edges) {
        if (d.union_set(edge[0], edge[1])){
            res --;
        }
    }

    cout<<"completed";

}