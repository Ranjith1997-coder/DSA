#include"../stdc++.h"
using namespace std;


string longest_palinromic_substring(string s) {

    int res = 1;
    string output;
    for (int i = 0; i < s.length(); i++) {
        int tmp_len = 1;
        int j = 0;
        while (true){
            if ((i-j < 0) || (i+j >= s.length())) {
                j--;
                break;
            }
            if (s[i+j] == s[i-j]) {
                j++;
            } else {
                j--;
                break;
            }
        }
        tmp_len = 2*j + 1;
        if (tmp_len > res) {
            res = tmp_len;
            output = s.substr(i-j, tmp_len);
        }
    }

    return output;

}

int main() {
    string s = "ababd";

    string res = longest_palinromic_substring(s);

}