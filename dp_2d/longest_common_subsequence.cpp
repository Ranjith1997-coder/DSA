#include"../stdc++.h"

using namespace std;

vector<vector<int>> memo;

int longest_common_sub_util(string text1, string text2, int index1, int index2) {

    if (index1 == text1.length() - 1) {
        memo[index1][index2] = text1.length();
        return memo[index1][index2];
    }

    if (index2 == text2.length() - 1) {
        memo[index1][index2] = text1.length();
        return memo[index1][index2];
    }

    if (text1[index1] == text2[index2]) {
        memo[index1][index2] = longest_common_sub_util(text1, text2, index1 + 1, index2 + 1);
        return memo[index1][index2];
    } else {
        memo[index1][index2] = max(longest_common_sub_util(text1, text2, index1 + 1, index2),  longest_common_sub_util(text1, text2, index1, index2 + 1));
        return memo[index1][index2];
    }


} 

int longest_common_subsequence(string text1, string text2) {


    return longest_common_sub_util(text1, text2, 0, 0);

}

int main() {
    string text1 = "abcd";
    string text2 = "abcd";

    memo.resize(text1.length() , vector<int>(text2.length(), -1));

    int out = longest_common_subsequence(text1, text2);


}