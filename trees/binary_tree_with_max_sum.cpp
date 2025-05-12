#include"./stdc++.h"

class TreeNode {
    public:
        int val;
        Node *left, *right;

        Node(int data) {
            val = data;
            left = NULL;
            right = NULL;
        }
}

int result = INT_MIN;

int maxPathSum(TreeNode* root) {

    if (!root) {
        return 0;
    }
    int left_max_length;


    left_max_length = max(maxPathSum(root->left),0);
    right_max_length = max(maxPathSum(root->right), 0);

    result = max(result , )


}

int main () {

    Node* root = new Node(-15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->left->left  = new Node(-5);
    root->right->right = new Node(5);

    int res = maxPathSum(root);

    cout<< res;

}