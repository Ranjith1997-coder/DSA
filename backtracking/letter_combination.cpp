#include"../stdc++.h"

using namespace std;

unordered_map <char, string> letter_digit_map = {
    {'1' , ""},
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"}
};


void letter_combination_util(string digits, int index, string substring , vector<string>& result) {
    if (index == digits.length() ) {
        result.push_back(substring);
        return;
    }

    for(int i = 0; i < letter_digit_map[digits[index]].length(); i++) {
        letter_combination_util(digits, index + 1, substring + letter_digit_map[digits[index]][i], result);
    }

    return;

}

vector<string> letter_combination(string digits) {

    vector<string> res;
    string substring;
    letter_combination_util(digits, 0, substring, res);

    return res;

}

int main() {
    string digits = "34";
    vector<string> res = letter_combination(digits);
}