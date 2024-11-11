#include <iostream>

using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}
Node;

typedef struct List{
    int size;
    Node* head;
}
List;

void init(List* l){
    l->size = 0;
    l->head = nullptr;
}

Node* initNode(int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

int isEmpty(List* l){
    return(l->size == 0);
}

void insertFirst(List* l, Node* newNode){
    if(isEmpty(l)){
        l->size++;
        l->head = newNode;
    }
}

void insertNode(Node* newNode, Node* curNode, List* l){
    curNode->next = newNode;
    l->size++;
}

void remove(List* l, int val){
    Node* p = l->head;
    if(p->data = val){
        l->head = p->next;
        delete p;
        l->size --;
        return;
    }
    
    Node* q = p->next;
    int cnt = 1;
    while((p->data != val) && (cnt < l->size)){
        q = p;
        p = p->next;
    }

    if(p != nullptr){
        q->next = p->next;
        l->size --;
        delete p;
    }
}

void printList(List* l){
    Node* p = l->head;
    while(p != nullptr){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}