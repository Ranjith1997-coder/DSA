#include"../stdc++.h"

using namespace std;

vector<vector<int>> memo;

int last_stone_weight_util(vector<int> stones, int total, int target, int index, int sum) {

    if ((sum >= target) || (index >= stones.size())) {
        return abs(total - 2 * sum);
    }



    return min(last_stone_weight_util(stones, total, target, index+1 , sum + stones[index]),
                last_stone_weight_util(stones, total, target, index+1 , sum));

}

int last_stone_weight(vector<int> stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = (sum/2) +1;
    memo = vector<vector<int>>(stones.size(), vector<int>(target, -1));

    return last_stone_weight_util(stones, sum , target, 0, 0);

}

int main() {
    vector<int> stones = {31,26,33,21,40};

    int out = last_stone_weight(stones);

}