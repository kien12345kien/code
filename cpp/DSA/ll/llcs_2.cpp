#include <iostream>
#include <cstdlib>

typedef struct node
{
    int data;
    struct node *next;
}
Node;

int main(int argc, char*argv[])
{
    node *list = nullptr;
    for (int i = 1; i < argc; i++)
    {
        int data = atoi(argv[i]);

        Node *n = new Node;
        if(n == nullptr)
        {
            return 1;
        }
        n->data = data;
        n->next = nullptr;

        n->next = list;
        list = n;

    }

    node *ptr = list;
    while (ptr != nullptr)
    {   
        /* code */
        std::cout << ptr->data << " ";
        ptr = ptr->next; 
    }
    
    ptr = list;
    while (ptr != nullptr)
    {
        node* next = ptr->next;
        delete ptr;
        ptr = next;
    }
    
    
}