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
    Node *front, *back;
    int size;
}
Queue;

void init(Queue *q)
{
    q->size = 0;
    q->back = nullptr;
    q->front = nullptr;
}

int isEmpty(Queue* q)
{
    return (q->front == nullptr);
}

void enqueue(Queue *q, int val) {
    Node *p = new Node;
    p->data = val;
    p->next = nullptr;  // New node will be the new back of the queue
    
    (q->front ==  nullptr) ?    (q->front = q->back = p) :  // Queue is empty
                                (q->back->next = p,         // Link current back node to new node
                                 q->back = p);               // Update back to new node
    q->size++;
}


void dequeue(Queue *q)
{
    if (isEmpty(q))
        return;
    
    Node *temp = q->front;  // Node to be removed
    q->front = q->front->next;  // Update front to the next node

    // If the queue becomes empty after dequeue, update the back pointer
    if (q->front == nullptr) {
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
        std::cout << "Dequeued: " << myQueue.front->data << std::endl;
        dequeue(&myQueue);
    }

    return 0;
}