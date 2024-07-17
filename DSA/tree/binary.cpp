#include <iostream>

using namespace std;

typedef struct TreeNode{
    int val;
    struct TreeNode* parent;
    struct TreeNode* tLeft;
    struct TreeNode* tRight;
}
TreeNode;

TreeNode* init(TreeNode* tree, int val){
    tree = new TreeNode;
    tree->val = val;
    tree->tLeft = nullptr;
    tree->tRight = nullptr;    
}