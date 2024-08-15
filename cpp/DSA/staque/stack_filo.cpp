#include <iostream>
#include <stack>
// FIFO
// Create Node
typedef struct Node
{
    int data;
    struct Node *next;
}
Node;

//Create Stack to calculate size of stack
typedef struct Stack
{
    int size;
    Node *top;
}
Stack;

//  set default value for size and node top of stack
void init(Stack *s)
{
    s->size = 0;
    s->top = nullptr;
}

//  Check stack is empty
int isEmpty(Stack *s)
{
    return (s->size == 0);
}

//  push node in stack
int push(int newData, Stack* s)
{
    Node *p = new Node;     // Create each node for each newData
    if (p == nullptr)
    {
        return 0;
    }

    p->data = newData;
    p->next = s->top;       
    s->top = p;
    s->size++;
    return 1;
}

int pop(Stack *s)
{
    Node *p;
    if (isEmpty(s))             //Check stack empty
        return 0;

    p = s->top;                 
    s->top = s->top->next;
    s->size--;
    delete p;
    return 1;
}

int main()
{
    // Example usage
    Stack myStack;                  //  Create a stack
    init(&myStack);                 //  Set value for stakc

    push(10, &myStack);             
    push(20, &myStack);
    push(30, &myStack);

    while (!isEmpty(&myStack))
    {
        std::cout << "Popped: " << myStack.top->data << std::endl;
        pop(&myStack);
    }

    return 0;
}
