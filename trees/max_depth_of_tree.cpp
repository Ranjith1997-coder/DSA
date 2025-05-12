#include"./stdc++.h"

class Node {
    public:
        int data;
        Node *left, *right;
        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
}

int maxDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}