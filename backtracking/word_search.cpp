#include"../stdc++.h"

using namespace std;

bool word_search_util(vector<vector<char>> box,string word, vector<vector<bool>>& visited, int i , int j, int index) {

    if ((i < 0) || (i >= box.size()) || (j < 0) || (j >= box[0].size())){
        return false;
    }

    if ((box[i][j] != word[index]) || (visited[i][j] == true) ){
        return false;
    }

    if ((box[i][j] == word[index]) && (index == word.length() - 1)){
        return true;
    }

    visited[i][j] = true;

    bool result = (word_search_util(box, word, visited, i + 1, j, index + 1) ||
                  word_search_util(box, word, visited, i - 1, j, index + 1) ||
                  word_search_util(box, word, visited, i , j+1, index + 1) ||
                  word_search_util(box, word, visited, i , j - 1, index + 1));

    visited[i][j] = false;

    return result;

}

bool word_search(vector<vector<char>>& box, string word) {

    vector<vector<bool>>  visited(box.size(), vector<bool>(box[0].size(), 0));
    bool result = false;
    for(int i = 0; i < box.size(); i++){
        for (int j= 0; j< box[0].size(); j++) {
            if (box[i][j] == word[0]) {
                result = word_search_util(box, word,  visited, i , j , 0);
                if (result) {
                    return result;
                }
            }
        }
    }

    return result;

}


int main() {

    vector<vector<char>> box = {
        {'A','B','C','D'},
        {'S','A','A','T'},
        {'A','C','A','E'}
    };

    string word = "CAT";

    bool is_avai = word_search(box, word);

}