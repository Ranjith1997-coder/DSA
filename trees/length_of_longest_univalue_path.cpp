#include"../stdc++.h"

using namespace std;

struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
};

TreeNode* create_tree_node(int val){
    TreeNode* new_node = new TreeNode();
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}

TreeNode* de_serialize(vector<string> tree_serialized){

    if (tree_serialized.empty()) {
        return NULL;
    }

    int index = 0;
    queue<TreeNode*> q;
    int val = stoi(tree_serialized[index]);
    TreeNode* root  = create_tree_node(val);


    q.push(root);
    index++;

    TreeNode* new_node = NULL;
    while(!q.empty()){

        new_node = q.front();
        q.pop();

        if ((index < tree_serialized.size()) && (tree_serialized[index] != "null")) {
            new_node->left = create_tree_node(stoi(tree_serialized[index]));
            q.push(new_node->left);
            index++;
        }else{
            new_node->left = NULL;
            index++;
        }

        if ((index < tree_serialized.size()) && (tree_serialized[index] != "null")) {
            new_node->right = create_tree_node(stoi(tree_serialized[index]));
            q.push(new_node->right);
            index++;
        }else{
            new_node->right = NULL;
            index++;
        }

    }

    return root;

}

int max = 0;

int length_of_longest_univalue_path(TreeNode* root){
    if (root == NULL) {
        return 0;
    }

    left = length_of_longest_univalue_path(root->left);
    right = length_of_longest_univalue_path(root->right);

    

}



int main(){
    vector<string> tree_serialized = {"5","4","5","1", "1", "null","5"};

    TreeNode* root = de_serialize(tree_serialized);

    int res = length_of_longest_univalue_path(root);

}