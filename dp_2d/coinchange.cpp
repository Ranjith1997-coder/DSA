#include"../stdc++.h" 

using namespace std;

vector<vector<int>> memo;

int coinchange_util(vector<int> coins, int target, int index, int steps, vector<int> subset){

    if ((target<0) || (index < 0)) {
        return INT_MAX;
    }

    if (target == 0) {
        memo[index][target] = steps;
        return memo[index][target];
    }

    if (memo[index][target] != -1) {
        return memo[index][target];
    }
    subset.push_back(coins[index]);
    int chosen = coinchange_util(coins, target - coins[index], index, steps + 1, subset);
    subset.pop_back();
    int not_chosen = coinchange_util(coins, target , index -1 , steps, subset);

    memo[index][target] =  min(chosen, not_chosen);

    return memo[index][target];
}

int coinchange(vector<int> coins, int target) {

    memo = vector<vector<int>>(coins.size() + 1, vector<int>(target + 1, -1));
    vector<int> subset;
    return coinchange_util(coins, target, coins.size() -1 , 0 , subset);
}

int main(){
    vector<int> coins = {1,2,5};

    int target = 11;

    int output = coinchange(coins, target);
}