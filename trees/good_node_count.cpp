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
        cout<<node->data;

        if (node->left){
            q.push(node->left);
        }
        if (node->right){
            q.push(node->right);
        }
        
    } 
}

void goodNode_util (Node* root , int& res, int max) {
    if (!root) {
        return;
    }
    if (root->data >= max) {
        res = res + 1;
        max = root->data;
    }

    goodNode_util(root->left, res, max);
    goodNode_util(root->right, res, max);
}
int goodNodes(Node* root) {
    
    int result = 0;
    int max = -1;
    goodNode_util(root , result, max);

    return result;
    
}


int main() {
      
    // Representation of input BST:
  //            2
  //           /  
  //          1    1
  //        /   \     
  //       4    12   
  //           /   \   
  //         10    14  
  Node* root = new Node(2);
  root->left = new Node(1);
  root->right = new Node(1);
  root->left->left = new Node(3);
//   root->left->right = new Node(12);
  root->right->left = new Node(1);
  root->right->right = new Node(5);

//   Node* n1 = root->left->left; // Node 4
//   Node* n2 = root->left->right->right; // Node 14

  int res = goodNodes(root);
  cout<< res;

  return 0;
}