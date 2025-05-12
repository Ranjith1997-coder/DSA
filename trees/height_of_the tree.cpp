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

void levelOrder(Node* root){

    queue<Node*> q ;
    Node* node = NULL;

    q.push(root);

    while(!q.empty()) {
        node = q.front();
        q.pop();
        cout<<node->data << " ";

        if (node->left){
            q.push(node->left);
        }
        if (node->right){
            q.push(node->right);
        }
        
    } 
}

int height(Node* tree_node) {
    queue<Node*> q ;
    Node* tmp = NULL;
    int level_node_count =0;
    int height = 0;

    if (tree_node == NULL){
        return 0;
    }

    q.push(tree_node);

    while(!q.empty()) {
        height++;
        level_node_count = q.size();
        for (int i = 0; i < level_node_count ; i ++) {
            tmp = q.front();
            q.pop();
            if (tmp->left){
                q.push(tmp->left);
            }
            if (tmp->right){
                q.push(tmp->right);
            }
        }
        
    }

    return height;

}

int main() {
  
    // Representation of the input tree:
    //     12
    //    /  \
    //   8   18
    //  / \
    // 5   11
    Node *root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);

    // levelOrder(root);
    
    cout << height(root);
    
    return 0;
}