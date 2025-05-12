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

int house_robber_3(TreeNode* root){

    queue<pair<TreeNode*, int>> q;

    q.push({root, 1});
    int red_sum = 0;
    int black_sum = 0;

    pair<TreeNode*, int> new_node_pair;
    TreeNode* node;

    while(!q.empty()) {
        new_node_pair = q.front();
        node = new_node_pair.first;
        q.pop();

        if (new_node_pair.second == 1) {
            red_sum += new_node_pair.first->val;
        } else {
            black_sum += new_node_pair.first->val;
        }

        if (node->left != NULL) {
            q.push({node->left , -1 * new_node_pair.second});
        }

        if (node->right != NULL) {
            q.push({node->right , -1 * new_node_pair.second});
        }
    
    }

    return max(red_sum, black_sum);

}


int main(){
    vector<string> tree_serialized = {"3","2","3","null","3","null","1"};

    TreeNode* root = de_serialize(tree_serialized);

    int res = house_robber_3(root);

}