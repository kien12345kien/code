#include <iostream>
#include <cstdlib>

typedef struct node
{
    int data;
    struct node *link;
}
Node;

int main()
{
    Node *head = new Node;
    head->data = 45;
    head->link = nullptr;
    

    Node *current = new Node;
    current->data = 98;
    current->link = nullptr;

    head->link = current;
    return 0;

    std::cout << head << std::endl << current; 
}