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
    return tree;    
}

void NLR(TreeNode* tree){
    if(tree == nullptr) return;

    cout << tree->val;

    NLR(tree->tLeft);
    NLR(tree->tRight);
}

TreeNode* insert(TreeNode* tree, int x){
    if(tree == nullptr){
        tree = init(tree,x);
        return tree;
    }

    if (x == tree->val);
}