#include <iostream>

// FILO
typedef struct Node
{
    int data;
    struct Node* next;
}
Node;

typedef struct Queue
{
    Node *top, *back;
    int size;
}
Queue;

void init(Queue *q)
{
    q->size = 0;
    q->back = nullptr;
    q->top = nullptr;
}

int isEmpty(Queue* q)
{
    return (q->top == nullptr);
}

void enqueue(Queue *q, int val) {
    Node *p = new Node;
    p->data = val;
    p->next = nullptr;  // New node will be the new back of the queue
    
    (q->top ==  nullptr) ?    (q->top = q->back = p) :  // Queue is empty
                                (q->back->next = p,         // Link current back node to new node
                                 q->back = p);               // Update back to new node
    q->size++;
}


void dequeue(Queue *q)
{
    if (isEmpty(q))
        return;
    
    Node *temp = q->top;  // Node to be removed
    q->top = q->top->next;  // Update front to the next node

    // If the queue becomes empty after dequeue, update the back pointer
    if (q->top == nullptr) {
        q->back = nullptr;
    }

    delete temp;  // Free the memory of the removed node
    q->size--;
}


int main()
{
    // Example usage
    Queue myQueue;
    init(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    while (!isEmpty(&myQueue))
    {
        std::cout << "Dequeued: " << myQueue.top->data << std::endl;
        dequeue(&myQueue);
    }

    return 0;
}