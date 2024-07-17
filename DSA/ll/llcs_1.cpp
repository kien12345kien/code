#include <iostream>
#include <string>
#include <cstdlib>

typedef struct node
{
    int number;
    struct node *next;
}
Node;

int main (int argc, char* argv[])
{
    Node *list = nullptr;

    for(int i = 1; i < argc; i++)
    {
        int number = std::stoi(argv[i]); // Convert the string to an integer


        Node *n = new Node;
        if(n == nullptr)
        {
            return 1;
        }
        n->number = number;
        n->next = nullptr;
// Các số sau đó sẽ được thêm vào sau số đã có sẵn
        n->next = list;
        list = n; // Current node List become node n which have all struct of Node (int number và struct node* next)
    }


    node *ptr = list;
    while (ptr != nullptr)
    {
        /* code */
        std::cout << ptr->number;
        ptr = ptr->next;
    }
    ptr = list;
    while (ptr != nullptr)
    {
        /* code */
        node* next = ptr->next;
        delete[] ptr;
        ptr = ptr->next;
    }
    
}

