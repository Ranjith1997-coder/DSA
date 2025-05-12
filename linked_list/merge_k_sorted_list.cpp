#include"../stdc++.h"

using namespace std;

typedef struct Node {
    int val;
    Node* next;
}Node;


Node* merge_util(Node* head1, Node* head2) {
    if(head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    if (head1->val <= head2->val) {
        head1->next = merge_util(head1->next, head2);
        return head1;
    }else {
        head2->next = merge_util(head1, head2->next);
        return head2;
    }

}


Node* merge_k_sorted(vector<Node*> list){
    if (list.empty()) {
        return NULL;
    }
    int size = 0;
    int i = 0;
    Node* result;
    while(list.size() != 1) {
        size = list.size();
        if (size%2 != 0){
            size = size-1;
        }
        for (i = 0; i < size; i = i + 2){
            result = merge_util(list[i], list[i+1]);
            list.push_back(result);
        }
        
        list.erase(list.begin(), list.begin() + i);
    }

    return list[0];

}


int main() {
    vector<Node*> list;

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

    Node * root3 = new Node();
    root3->val = 7;
    root3->next = new Node();
    root3->next->val = 8;
    root3->next->next = new Node();
    root3->next->next->val = 9;


    list.push_back(root1);
    list.push_back(root2);
    list.push_back(root3);

    Node* result = merge_k_sorted(list);

}