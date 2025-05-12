#include"../stdc++.h"

using namespace std;

struct TrieNode {
    bool end_of_word;
    unordered_map<char, TrieNode*> children;
};

class Trie {
        
    public: 
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        
        void add_word(string word) {
            TrieNode* node = root;

            for(auto ch : word) {
                if (node->children.find(ch) == node->children.end()) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }

            node->end_of_word = true;
        }
};

vector<pair<int, int>> directions = {{1,0} , {-1, 0 }, {0,1}, {0,-1}};

void dfs(int i, int j,vector<vector<char>>& board, vector<vector<bool>>& visited, TrieNode* trie_node, vector<string>& res, string word) {

    if ((i < 0) || (i >= board.size()) || ( j < 0) || (j >= board[i].size()) || (visited[i][j] == true) || 
        (trie_node->children.find(board[i][j]) == trie_node->children.end())) {
            return ;
        }

    visited[i][j] = true;
    trie_node = trie_node->children[board[i][j]];
    word += board[i][j];

    if (trie_node->end_of_word) {
        res.push_back(word);
    }

    for (auto dir: directions) {
        dfs(i + dir.first , j + dir.second, board, visited, trie_node, res, word);
    }

    visited[i][j] = false;

}



vector<string> word_search(vector<vector<char>> board, vector<string> words) {

    Trie trie;
    vector<string> res;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

    for (auto word : words){
        trie.add_word(word);
    }
    string word = ""; 
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            dfs(i , j, board, visited, trie.root, res, word);
        }
    }

    return res;

}


int main() {
    vector<vector<char>> board = {
        {'a','b','c','d'},
        {'s','a','a','t'},
        {'a','c','k','e'},
        {'a','c','d','n'}
      };

    vector<string> words = {"bat","cat","back","backend","stack"};

    vector<string> res =  word_search(board, words);
    
}