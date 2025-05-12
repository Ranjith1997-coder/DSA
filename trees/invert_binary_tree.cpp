#include"../stdc++.h"

using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void mirror(Node* tree_node) {

    if (tree_node == NULL){
        return;
    }
    Node * tmp_node = NULL;
    mirror(tree_node->left);
    mirror(tree_node->right);

    tmp_node = tree_node->left;
    tree_node->left = tree_node->right;
    tree_node->right = tmp_node;

    

    return;
}


void levelOrder(Node* root){

    queue<Node*> q ;
    Node* node = NULL;

    q.push(root);

    while(!q.empty()) {
        node = q.front();
        q.pop();
        cout<<node->data;

        if (node->left){
            q.push(node->left);
        }
        if (node->right){
            q.push(node->right);
        }
        
    } 
}


int main() {

    // Input Tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    mirror(root);
  
    // Mirror Tree:
    //       1
    //      / \
    //     3   2
    //        / \
    //       5   4
    levelOrder(root);

    return 0;
}