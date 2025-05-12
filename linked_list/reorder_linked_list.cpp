#include"../stdc++.h"

using namespace std;

typedef struct Node {
    int val;
    Node* next;
}Node;

void reorder_util(Node* reverse , Node** head) {
    if (reverse == NULL) {
        return ;
    }
    reorder_util(reverse->next , head);
    if (*head == NULL) {
        return;
    }
    if (reverse == (*head)) {
        (*head)->next = NULL;
        (*head) = NULL;
        return;
    }else if ((*head)->next == reverse){
        reverse->next = NULL;
        (*head) = NULL;
    } else {
        Node* tmp_node = (*head)->next;
        (*head)->next = reverse;
        reverse->next = tmp_node;
        *head = tmp_node;
    }

    return;

}

Node* reorder(Node* root) {

    Node* head = root;

    reorder_util(head, &head);

    return root;

}


int main() {
    Node * root1 = new Node();
    root1->val = 0;
    root1->next = new Node();
    root1->next->val = 1;
    root1->next->next = new Node();
    root1->next->next->val = 2;
    root1->next->next->next = new Node();
    root1->next->next->next->val = 3;
    // root1->next->next->next->next = new Node();
    // root1->next->next->next->next->val = 4;

    Node* result = reorder(root1);
}