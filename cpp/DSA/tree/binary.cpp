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

    else{
        // (x < tree->val) ? 
        // tree->tLeft = insert(tree->tLeft, x) : tree->tRight = insert(tree->tRight, x);

        if(x < tree->val){
            tree->tLeft = insert(tree->tLeft, x);
        }
        else    
            tree->tRight = insert(tree->tRight, x);
    
    }
    return tree;
}

int main(){
    TreeNode* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 30);

    cout << "NLR traversak if the tree: ";
    NLR(root);

    return 0;
}