#include"../stdc++.h"

using namespace std;

bool is_pattern_match_util(string s , string p , int index1, int index2) {
    
    if (index1 == s.size() -1 ){
        if (index2 == p.size() - 1) {
            return true;
        } else {
            return false;
        }
    } 

    bool match = (index2 < p.size()) && ((s[index1] == s[index2]) || (s[index2] == '.'));

    if (match && (index2 + 1 < p.size() - 1) && (p[index2 + 1] == '*')) {
        match = (is_pattern_match_util(s, p , index1 + 1, index2) || 
                is_pattern_match_util(s, p , index1 + 1, index2 + 2));
        return match;
    } 

    if (match) {
        return is_pattern_match_util(s, p , index1+1, index2+1);
    }

    return false;

}

bool is_pattern_match(string s , string p ){

    return is_pattern_match_util(s, p , 0, 0);
}

int main() {

    string s = "aabaa";
    string p = "a*baa";
    
    bool out = is_pattern_match(s, p);
}