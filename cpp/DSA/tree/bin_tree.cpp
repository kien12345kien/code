#include <iostream>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* parent;
    TreeNode* tLeft;
    TreeNode* tRight;

    TreeNode(int val) : data(val), parent(nullptr), tLeft(nullptr), tRight(nullptr) {}
};

class BinarySearchTree{
    private:
        TreeNode* root;
        
        TreeNode* insert(TreeNode* node, int x){
            if (node == nullptr){
                return new TreeNode(x);
            }

            if (x < node->data) {
                node->tLeft = insert(node->tLeft, x);
                node->tLeft->parent = node;
            }
            else{
                node->tRight = insert(node->tRight, x);
                node->tRight->parent = node;
            }
            return node;
        }

        TreeNode* findmin(TreeNode* node) const{
            while (node->tLeft != nullptr)      node = node->tLeft;
            return node;
        }

        TreeNode* deleteNode(TreeNode* node, int key){
            if (node == nullptr)    return node;

            if(node->data > key){
                node->tLeft = deleteNode(node->tLeft, key);
            }

            else if(node->data < key){
                node->tRight = deleteNode(node->tRight, key);
            }

            else{
                if(node->tLeft == nullptr){
                    TreeNode* temp = node->tRight;
                    delete node;
                    return temp;
                }

                else if(node->tRight == nullptr){
                    TreeNode* temp = node->tLeft;
                    delete node;
                    return temp;
                }

                TreeNode* temp = findmin(node->tRight);
                node->data = temp->data;
                node->tRight = deleteNode(node->tRight, temp->data);
            }
            return node;
        }

        void NLR(TreeNode* node) const{
            if (node == nullptr)    return;

            cout << node->data << endl;
            NLR(node->tLeft);
            NLR(node->tRight);
        }
        
    public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int x) {
        root = insert(root, x);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void NLR() const {
        NLR(root);
    }

};

int main() {
    BinarySearchTree bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(3);
    bst.insert(60);
    bst.insert(7);
    bst.insert(15);
    bst.insert(30);
    bst.insert(2);
    bst.insert(50);
    bst.insert(19);

    cout << "NLR traversal of the tree: " << endl;
    bst.NLR();

    return 0;
}