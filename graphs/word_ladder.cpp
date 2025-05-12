#include"../stdc++.h"

using namespace std;

vector<string> get_neighbours(string word, vector<string> word_list) {
    int count =0;
    vector<string> output;
    for (auto _word : word_list) {
        count = 0;
        for (int i =0 ; i < word.size(); i++) {
            if (word[i] != _word[i]) {
                count++;
            }
        }
        if (count == 1) {
            output.push_back(_word);
        }
    }
    return output;

}


int word_ladder(string begin_word, string end_word, vector<string> word_list){

    queue<string> q;
    int res = 0;
    q.push(begin_word);
    unordered_map<string, bool> visited ;

    visited[begin_word] = true;
    for (int i = 0; i < word_list.size(); i ++) {
        visited[word_list[i]] = false;
    }

    vector<string> neighbours;
    int queue_size= 0;

    string word;

    while(!q.empty()) {
        queue_size = q.size();
        for (int i = 0; i < queue_size; i++) {
            word = q.front();
            q.pop();
            visited[word] = true;
            if (word == end_word) {
                return res + 1;
            }
            neighbours = get_neighbours(word, word_list);
            for (auto neighbour : neighbours) {
                if (visited[neighbour] == 0) {
                    q.push(neighbour);
                }
            }

        }
        res++;   
    }
    return 0;
}


int main(){
    string begin_word = "cat";
    string end_word = "sag";

    vector<string> word_list = {"bat","bag","sag","dag","dot"};

    int res = word_ladder(begin_word, end_word, word_list);

    cout<<"completed";
}