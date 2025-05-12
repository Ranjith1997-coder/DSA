#include"../stdc++.h"

using namespace std;

vector<int> memo;

int decode_ways_util(string s, int index ){
    if (index == s.size() - 1){
        memo[index] = 1;
        return memo[index];
    }

    if (index >= s.size()) {
        return 1;
    }

    if (memo[index] != -1 ) {
        return memo[index];
    }

    memo[index] = decode_ways_util(s, index + 1);

    if ((s[index] == '1') || ((s[index] == '2') && (index + 1 < s.size()) && (s[index+1] >= '1') && (s[index+1] <= '6'))) {
        memo[index] += decode_ways_util(s, index + 2);
    }

    return memo[index];

}

int decode_ways(string s) {

    int res = 0;

    if (s[0] == '0') {
        return 0;
    }
    memo = vector<int>(s.size()+1, -1);
    memo[s.size()] = 1;
    return decode_ways_util(s, 0);


}
int main() {
    string s = "1112";

    int res = decode_ways(s);
}