#include <iostream>
#include <cstdlib>

typedef struct node
{
    int number;
    struct node* next;
}
Node;

int main(int agrc, char *agrv[])
{
    Node *list = nullptr;
    for(int i = 1; i < agrc; i++)
    {
        int number = atoi(agrv[i]);

        Node *n = new Node;
        if(n == nullptr)
        {
            return 1;
        }
        n->number = number;
        n->next = nullptr;

        // Kiểm tra list có trống hay k
        if(list == nullptr)
        {
            list = n;
        }
        
        else
        {
            // Lặp lại các node trong list
            for(Node *ptr = list; ptr != nullptr; ptr = ptr->next)
            {
                if (ptr->next == nullptr)
                {
                    ptr->next = n;
                    break;
                }
                
            }
        }
    }

    // Print numbers
    for(Node *ptr = list; ptr != nullptr; ptr = ptr->next)
    {
        std::cout << ptr->number;
    }

    //Free memory
    Node* ptr = list;
    while(ptr != nullptr)
    {
        Node* next = ptr->next;
        delete ptr;
        ptr = next;
    }
}