#include"../stdc++.h"

using namespace std;

int long_substring_without_rep_char(string s){
    unordered_set<char> char_set;
    int j= 0;
    int count = 0;
    int res = 0;
    int i = 0;
    while(i < s.size()){
        if (char_set.count(s[i]) == 0) {
            char_set.insert(s[i]);
            count++; 
            res = max(res, count);
            i++;
        }else {
            char_set.erase(s[j]);
            count--;
            j++;
        }
    }

    return res;
}

int main(){
    string s = "xxxx";

    int res = long_substring_without_rep_char(s);
}