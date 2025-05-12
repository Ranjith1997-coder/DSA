#include"../stdc++.h"

using namespace std;

class DJS{
    private :
        vector<int> parent ;
        vector<int> rank;
    public:
        DJS(int size) {
            parent.resize(size);
            rank = vector<int>(size, 1);

            for (int i = 0; i < size; i++){
                parent[i] = i;
            }
        }

        int find(int a){
            int x = a;
            while( parent[x] != x){
                parent[x] = parent[parent[x]];
                x = parent[x];
            }

            return x;
        }

        bool union_set(int a , int b){
            int p_a = find(a);
            int p_b = find(b);

            if (p_a == p_b){
                return false;
            }
            if (rank[p_a] >= rank[p_b]){
                parent[p_b] = p_a;
                rank[p_a] += rank[p_b];
            }else {
                parent[p_a] = p_b;
                rank[p_b] += rank[p_a];
            }
            return true;
        }

};

int main() {
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},
    {"John","johnsmith@mail.com","john00@mail.com"},
    {"Mary","mary@mail.com"},
    {"John","johnnybravo@mail.com"}};


    DJS djs(accounts.size());
    unordered_map<string , int> account_index_map;

    for (int i = 0; i<accounts.size(); i ++){
        for (int j = 1; j < accounts[i].size(); j++){
            if (account_index_map.find(accounts[i][j]) == account_index_map.end()){
                account_index_map[accounts[i][j]] = i;
            } else {
                djs.union_set(i, account_index_map[accounts[i][j]]);
            }
        }
    }


    unordered_map<int , vector<string>> group_index;
    int leader;
    for (auto email_pair : account_index_map ){
        leader = djs.find(email_pair.second);
        group_index[leader].push_back(email_pair.first);
    }


    vector<vector<string>> result;
    for (auto index_pair : group_index ){
        sort(index_pair.second.begin(), index_pair.second.end());
        vector<string> merged;
        merged.push_back(accounts[index_pair.first][0]);
        merged.insert(merged.end(), index_pair.second.begin(), index_pair.second.end());
        result.push_back(merged);
    }   

    
}