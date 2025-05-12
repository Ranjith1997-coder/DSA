#include"../stdc++.h"

using namespace std;

typedef struct Node {
    int val;
    Node* next;
}Node;

Node* merge(Node* root1, Node* root2){
    if (!root1) {
        return root2;
    }

    if (!root2) {
        return root1;
    }

    if (root1->val <= root2->val) {
        root1->next = merge(root1->next, root2);
        return root1;
    } else {
        root2->next = merge(root1, root2->next);
        return root2;
    }
}

int main(){

    Node * root1 = new Node();
    root1->val = 1;
    root1->next = new Node();
    root1->next->val = 2;
    root1->next->next = new Node();
    root1->next->next->val = 4;

    Node * root2 = new Node();
    root2->val = 1;
    root2->next = new Node();
    root2->next->val = 3;
    root2->next->next = new Node();
    root2->next->next->val = 5;

    Node* result = merge(root1, root2);


}