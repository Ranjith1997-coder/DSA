#include"../stdc++.h"

using namespace std;


bool is_permu_available(string s1, string s2){

    unordered_map<int, int> s1_map;
    unordered_map<int, int> s2_map;

    for(int i =0; i < 26 ; i++){
        s1_map[i] = 0;
        s2_map[i] = 0;
    }

    for (int i =0; i < s1.size(); i++){
        s1_map[s1[i] - 'a']++;
        s2_map[s2[i] - 'a']++;
    }
    int match = 0;
    for(int i =0; i < 26 ; i++){
        if (s1_map[i]  == s2_map[i]){
            match++;
        }
    }

    int start_index = 0;
    int index = 0;
    for (int end_index = s1.size(); end_index < s2.size(); end_index++ ) {

        if (match == 26){
            return true;
        }

        index = s2[end_index] - 'a';
        s2_map[index]++;
        if (s2_map[index] == s1_map[index]) {
            match++;
        }else if (s1_map[index] + 1 == s2_map[index]){
            match--;
        }

        index = s2[start_index] - 'a';
        s2_map[index]--;
        if (s2_map[index] == s1_map[index]){
            match++;
        } else if (s1_map[index] - 1 == s2_map[index]){
            match--;
        }
        start_index++;
        
    }
    if (match == 26){
        return true;
    }
    return false;

}

int main() {
    string s1 = "abc";
    string s2 = "lecabee";

    bool res = is_permu_available(s1, s2);
}