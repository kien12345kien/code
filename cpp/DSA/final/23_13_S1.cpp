#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

// void petagonal_number(int n){
//     if(n < 0)   return;

//     int function = (3*pow(n,2)-n)/2;
//     cout << function << endl;
//     petagonal_number(n-1);
// }

// int main(){
//     int number = 4;
//     petagonal_number(number);
//     return 0;
// }

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

struct Node* createNode(int data){
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

struct QueueNode{
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Queue{
    struct QueueNode* front;
    struct QueueNode* rear;
}