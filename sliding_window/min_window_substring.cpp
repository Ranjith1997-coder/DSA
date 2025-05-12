#include"../stdc++.h"

using namespace std;

string min_window_substring(string s , string t){

    unordered_map<char, int> t_map ;
    unordered_map<char, int> s_map;

    for (auto ch : t){
        if (t_map.find(ch) == t_map.end()){
            t_map[ch] = 1;
        }else{
            t_map[ch]++;
        }
    }

    int l = 0;
    int r = 0;
    int match = 0;
    string res_string;
    int res_string_length = INT_MAX;
    while(r < s.size()){    
        if (t_map.find(s[r]) == t_map.end()){
            r++;
            continue;
        }
        
        if (s_map.find(s[r]) == s_map.end()){
            s_map[s[r]] = 1;
        }else{
            s_map[s[r]]++;
        }
        
        if (s_map[s[r]] == t_map[s[r]]){
            match++;
        }

        while(match == t.size()){
            if ( r -l + 1 < res_string_length) {
                res_string_length = r -l + 1;
                res_string = s.substr(l, res_string_length);
            }

            if (t_map.find(s[l]) != t_map.end()){
                s_map[s[l]]--;
                match--;
            }
            l++;
        }
        r++;


    }

    if (res_string_length == INT_MAX){
        return "";
    }

    return res_string;

}

int main(){
    string s = "x";
    string t = "xy";

    string res = min_window_substring(s, t);
}