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

    cout << tree->val << endl;

    NLR(tree->tLeft);
    NLR(tree->tRight);
}

TreeNode* findmin(TreeNode* tree){
    while (tree->tLeft != nullptr){
        tree = tree->tLeft;
    }
    return tree;
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

TreeNode* deleteNode(TreeNode* root, int key){
    if(root == nullptr) return root;

    if (key < root->val){
        root->tLeft = deleteNode(root->tLeft, key);
    }
    else if (key > root->val){
        root->tRight = deleteNode(root->tRight, key);
    }
    else{
        if (root->tLeft == nullptr){
            TreeNode* temp = root->tRight;
            delete root;
            return temp;
        }
        else if (root->tRight == nullptr){
            TreeNode* temp = root->tLeft;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor
        TreeNode* temp = findmin(root->tRight);

        // Copy the inorder successor's content to this node
        root->val = temp->val;

        // Delete the inorder successor
        root->tRight = deleteNode(root->tRight, temp->val);
    }
    return root;
}

int main(){
    TreeNode* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 60);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 30);
    root = insert(root, 2);
    root = insert(root, 50);
    root = insert(root, 19);

    cout << "NLR traversak if the tree: " << std::endl;
    NLR(root);

    return 0;
}