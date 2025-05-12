#include"../stdc++.h"

using namespace std;

typedef struct Node{
    int val;
    Node* next;
} Node;


Node* divide(Node* node) {

    if (node == NULL || node->next == NULL) {
        return node;
    }

    Node* slow= node, fast= node;
    Node* mid_plus_one = NULL;

    while((fast != NULL) || (fast->next != NULL)){
        slow->next;
        fast->next->next;
    }

    mid_plus_one = slow->next;
    slow->next = NULL;


}


void merge_sort(Node* node) {
    


    

    merge()




}

int main () {

    //4->3->5->2->1
    Node* result;
    Node * root = new Node();
    root->val = 4;
    root->next = new Node();
    root->next->val = 3;
    root->next->next = new Node();
    root->next->next->val = 5;
    root->next->next->next = new Node();
    root->next->next->next->val = 2;
    root->next->next->next->next = new Node();
    root->next->next->next->next->val = 1;

    merge_sort(root);


}








}