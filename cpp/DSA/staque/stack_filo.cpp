#include <iostream>
#include <stack>
// FIFO
typedef struct Node
{
    int data;
    struct Node *next;
}
Node;

typedef struct Stack
{
    int size;
    Node *top;
}
Stack;

void init(Stack *s)
{
    s->size = 0;
    s->top = nullptr;
}

int isEmpty(Stack *s)
{
    return (s->size == 0);
}

int push(int newData, Stack* s)
{
    Node *p = new Node;
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
    if (isEmpty(s))
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
    Stack myStack;
    init(&myStack);

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
