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

bool isValidBST_util(TreeNode* root, TreeNode** prevNode){
    if (root == NULL){
        return true;
    }

    bool result = isValidBST_util(root->left, prevNode);
    if (*prevNode == NULL) {
        *prevNode = root;
    } else {
        if ((*prevNode)->val >= root->val) {
            return false;
        }
        *prevNode = root;
    }
    result = result && isValidBST_util(root->right, prevNode);

    return result;

}

bool isValidBST(TreeNode* root) {

    TreeNode* prev_node = NULL;

    return isValidBST_util(root, &prev_node);

    
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);

    bool res = isValidBST(root);
}


