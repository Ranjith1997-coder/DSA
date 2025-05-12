#include"../stdc++.h"


using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


TreeNode* lowest_common_ancestor(TreeNode* root, int val1, int val2){

    if (!root){
        return NULL;
    }

    if ((root->val == val1) || (root->val == val2)){
        return root;
    }

    TreeNode* left = lowest_common_ancestor(root->left, val1, val2);
    TreeNode* right = lowest_common_ancestor(root->right, val1, val2);

    if ((left) && (right)) {
        return root;
    }

    return (left == NULL)? right: left;


}

bool count_num_turns(TreeNode* root, int val, char prev_turn, int& count){

    if ((root == NULL)){
        return false;
    }
    if (root->val == val){
        return true;
    }

    char next_turn = 'L';
    
    if (prev_turn != next_turn){
        count++;
    }

    if (count_num_turns(root->left, val, next_turn, count)){
        return true;
    }

    next_turn = 'R';

    if (prev_turn != next_turn){
        count++;
    }

    if (count_num_turns(root->right, val, next_turn, count)){
        return true;
    }

    count--;
    return false;
}

int count_num_turns(TreeNode* root, int val1, int val2) {

    int left_count = 0;
    int right_count = 0;
    int visited_count = 0;
    
    TreeNode* lca_node = lowest_common_ancestor(root, val1, val2);

    count_num_turns(lca_node->left, val1, 'L', left_count);
    count_num_turns(lca_node->right, val2, 'R', right_count);

    return left_count + right_count + 1;
}



int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int count = count_num_turns(root, 4, 6);

}