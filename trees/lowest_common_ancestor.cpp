#include"../stdc++.h"

using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode* lowest_common_ancestor(TreeNode* root, int val1, int val2){

    if (!root){
        return NULL;
    }

    if ((root->val == val1) || (root->val == val2)){
        return root;
    }

    TreeNode* left = lowest_common_ancestor(root->left, val1, val2);
    TreeNode* right = lowest_common_ancestor(root->right, val1, val2);

    if ((left) && (right)) {
        return root;
    }

    return (left == NULL)? right: left;


}


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode* lca = lowest_common_ancestor(root, 4, 5);

}
