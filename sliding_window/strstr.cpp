#include"../stdc++.h"

using namespace std;


vector<int> z_function(string s){


    vector<int> z_array(s.size(), -1);
    z_array[0] = 0;

    int l = 0;
    int r = 0;

    for (int index = 1; index < s.size(); index++){
        l = 0;
        r = index;
        while(s[l] == s[r]){
            l++;
            r++;
        }
        z_array[index] = r - index;  

    }

    return z_array;

}

int strstr_my_function(string haysack, string needle){

    // string new_conc_string = needle + "$" + haysack;
    string new_conc_string = "aabxaabxcaabxaabxay";

    vector<int> z_array = z_function(new_conc_string);

    return 0;


}

int main() {
    string haysack = "sadbutsad";
    string needle = "sad";

    int index = strstr_my_function(haysack, needle);

}