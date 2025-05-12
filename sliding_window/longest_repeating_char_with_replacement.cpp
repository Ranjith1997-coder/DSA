#include"../stdc++.h"

using namespace std;

int longest_repeating_char_with_replacement( string s , int k){
    int l = 0;
    int r = 0;
    unordered_map<char, int> map;
    int most_freq_count = 0;
    int res = 0;

    while(r < s.size()) {
        map[s[r]]++;
        most_freq_count = max(most_freq_count, map[s[r]]);

        while((r-l+1 - most_freq_count) > k){
            map[s[l]]--;
            l++;
        }
        res = max(res , r-l+1 );
        r++;

    }

    return res;
}

int main(){
    string s = "AAABABB";
    int k = 1;

    int res = longest_repeating_char_with_replacement(s, k);
}