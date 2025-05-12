#include "../stdc++.h"

using namespace std;

int sum(vector<int> v) {
    int sum = 0;
    for_each(v.begin(), v.end(), [&] (int n) {sum+= n; });
    return sum;
}

void combination_sum_util(vector<int> vec, vector<int>& subset, int index, int target, vector<vector<int>>& res){
    
    if (index >= vec.size()) {
        return;
    }
    if (sum(subset) >= target) {
        if (sum(subset) == target) {
            res.push_back(subset);
        }
        return;
    }

        subset.push_back(vec[index]);
        combination_sum_util(vec, subset, index, target, res);
        subset.pop_back();
        combination_sum_util(vec, subset, index+1, target, res);
    
    

    return;
}

vector<vector<int>> combination_sum(vector<int> vec , int target) {
    vector<vector<int>> res ;
    vector<int> subset;

    combination_sum_util(vec, subset, 0, target, res);

    return res;

}

int main() {
    vector<int> vec = {2,5,6,9};
    int target = 9;
    vector<vector<int>> res = combination_sum(vec, target);
    cout<<"completed";
}