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

string find_duplicates_util(TreeNode* root, vector<string>& res, unordered_set<string>& paths){

    if (root == NULL) {
        return "N";
    }

    string left_path = find_duplicates_util(root->left, res, paths);
    string right_path = find_duplicates_util(root->right, res, paths);

    string final_path = left_path + to_string(root->val) + right_path;

    if (paths.find(final_path) != paths.end()){
        res.push_back(final_path);
    }

    paths.insert(final_path);

    return final_path;

}

vector<string> find_duplicates(TreeNode* root){

    vector<string> res;

    unordered_set<string> paths;

    find_duplicates_util(root, res, paths);

    return res;

}

int main(){

    vector<string> tree_serialized = {"1","2","3","4","null","2","4","null","null","4"};


    TreeNode* root = de_serialize(tree_serialized);

    vector<string> res = find_duplicates(root);


}