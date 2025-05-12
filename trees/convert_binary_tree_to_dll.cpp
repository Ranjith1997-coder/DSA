#include"../stdc++.h"

using namespace std;

typedef struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

TreeNode* newNode(int data)
{
    TreeNode* new_node = new TreeNode;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

void BinaryTree2DoubleLinkedList (TreeNode* root, TreeNode** head) {
    if (!root || root->left== NULL) {
        return;
    }
    BinaryTree2DoubleLinkedList (root->left, head);

    *head = root;
    TreeNode* tempNode = root->right;

    root->right = root->left;
    root->left = NULL;
    while(root->right != NULL) {
        root = root->right;
    }
    root->right = tempNode;

    BinaryTree2DoubleLinkedList (root->right, head);
}

int main() {


    TreeNode* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    // Convert to DLL
    TreeNode* head = NULL;
    BinaryTree2DoubleLinkedList(root, &head);

}