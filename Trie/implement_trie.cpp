#include"../stdc++.h"

using namespace std;

class PrefixTree {
    public:
        unordered_map<char, PrefixTree*> node_map;
        bool is_end_of_word;
        PrefixTree() {
            bool is_end_of_word = false;   
        }
        
        void insert(string word) {
            PrefixTree* curr_node = this;
            for (int i = 0; i < word.length(); i++) {
                if (curr_node->node_map.find(word[i]) == curr_node->node_map.end()) {
                    curr_node->node_map[word[i]] = new PrefixTree();
                }
                curr_node = curr_node->node_map[word[i]];
            }
            curr_node->is_end_of_word = true;
        }
        
        bool search(string word) {
            PrefixTree* curr_node = this;
            for (int i = 0; i < word.length(); i++) {
                if (curr_node->node_map.find(word[i]) == curr_node->node_map.end()){
                    return false;
                }
                curr_node = curr_node->node_map[word[i]];
            }

            if (!curr_node->is_end_of_word){
                return false;
            }
            return true;

        }
        
        bool startsWith(string prefix) {
            PrefixTree* curr_node = this;
            for (int i = 0; i < prefix.length(); i++) {
                if (curr_node->node_map.find(prefix[i]) == curr_node->node_map.end()){
                    return false;
                }
                curr_node = curr_node->node_map[prefix[i]];
            }
            return true;

        }
    };

int main() {
    PrefixTree pt;

    pt.insert("ranjith");
    pt.insert("kumar");
    bool res = pt.search("kumar");



}