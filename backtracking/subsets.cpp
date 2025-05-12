#include"../stdc++.h"

using namespace std;

void generate_subset_util(vector<int> set, vector<int>& subset, int index , vector<vector<int>>& res) {
    if (index == set.size()){
        res.push_back(subset);
        return;
    }
    subset.push_back(set[index]);
    generate_subset_util(set, subset, index+1, res);
    subset.pop_back();
    generate_subset_util(set, subset, index+1, res);
    return;

}

vector<vector<int>> generate_subsets(vector<int> set) {
    vector<vector<int>> res;
    vector<int> subset;
    generate_subset_util(set, subset, 0, res);
    return res;
}

int main() {
    vector<int> set = {1,2,3};
    vector<vector<int>> subsets ;

    subsets = generate_subsets(set);
    cout<< "completed";
}