#include"../stdc++.h"

using namespace std;


void combination_sum_util(vector<int> vec, vector<int>& subset, int index, int target, vector<vector<int>>& res){

    if (target == 0) {
        res.push_back(subset);
        return;
    }

    if ((target < 0) || (index >= vec.size())){
        return;
    }
    int selected_num = vec[index];

    subset.push_back(vec[index]);
    combination_sum_util(vec, subset, index+1, target - vec[index], res );
    subset.pop_back();
    while(selected_num == vec[index]) {
        index++;
    }
    combination_sum_util(vec, subset, index, target, res );

}

vector<vector<int>> combination_sum_2(vector<int> vec , int target) {
    vector<vector<int>> res ;
    vector<int> subset;

    sort(vec.begin(), vec.end());

    combination_sum_util(vec, subset, 0, target, res);

    return res;

}

int main() {

    vector<int> vec = {9,2,2,4,6,1,5};
    int target = 8;
    vector<vector<int>> res = combination_sum_2(vec, target);
    cout<<"completed";

}