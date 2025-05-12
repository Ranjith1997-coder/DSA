#include"../stdc++.h"

using namespace std;

bool is_palinrome(string s, int i , int j) {
    
    while(i<=j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }

    return true;

}

void palinrome_partition_util(string s ,vector<string>& substring, int index, vector<vector<string>>& res) {
    if (index == s.length()) {
        res.push_back(substring);
        return;
    }
    int i = index;
    for (int j = index; j < s.length(); j++) {
        if (is_palinrome(s, i , j)) {
            substring.push_back(s.substr(i , j - i +1));
            palinrome_partition_util(s, substring, index + j - i + 1, res);
            substring.pop_back();
        }
    }

    return;

}

vector<vector<string>> palinrome_partition(string s) {

    vector<vector<string>> res;
    vector<string> substrings; 
    palinrome_partition_util(s,substrings, 0, res);

    return res;

}

int main() {
    string s = "aab";

    vector<vector<string>> res = palinrome_partition(s);

    cout<<"completed";

}