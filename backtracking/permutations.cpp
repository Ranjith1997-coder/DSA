#include"../stdc++.h"
using namespace std;

void swap(string& s , int i, int j){
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

void permut_util(string& s, vector<string>& res , int index){
    if (index == s.size() - 1) {
        res.push_back(s);
        return;
    }

    for(int i = index; i < s.size(); i++) {
        swap(s, i , index);
        permut_util(s, res, index + 1);
        swap(s, i , index);
    }

    return;

}

vector<string> permutations(string& s) {
    vector<string> vec ;
    permut_util(s, vec, 0);
    return vec;
}

int main() {

    string s = "ABC";
    vector<string>  res = permutations(s);

    cout<<"completed";

}