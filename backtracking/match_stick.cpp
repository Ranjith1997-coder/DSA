#include"../stdc++.h"

using namespace std;


bool makesquare_util(vector<int> matchsticks, int index, vector<int> subarray, int filled) {
    if ((filled == 4) && (index == matchsticks.size())) {
        return (((subarray[0]) == subarray[1]) && ((subarray[1]) == subarray[2]) && ((subarray[2]) == subarray[3]));
    } 

    if (((index == matchsticks.size()) && (filled != 4)) || ((index != matchsticks.size()) && (filled == 4))) {
        return false;
    }

    for (int i = index; i < matchsticks.size(); i++) {
        subarray[filled] += accumulate(matchsticks.begin() + index , matchsticks.begin() + i + 1, 0);
        if (makesquare_util(matchsticks, i + 1, subarray, filled + 1)){
            return true;
        }
            
        subarray[filled] = 0;
    }

    return false;


}


bool makesquares(vector<int> matchsticks) {
    
    vector<int> subarray(4, 0);
    return makesquare_util(matchsticks, 0, subarray, 0);

}

int main(){
    vector<int> matchsticks = {1,1,2,2,2,3};

    bool res = makesquares(matchsticks);
}