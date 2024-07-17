#include <iostream>
#include <string>
#include <cstdlib>
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

void enqueue(Queue *q, int val)
{
    Node *p = new Node;
    p->data = val;
    p->next = nullptr;
    if(q->front == nullptr)
    {
        q->front = q->back = p;
    }
    else
    {
        p->next = q->back;
        q->back = p;
    }
    q->size++;
}


void dequeue(Queue *q)
{
    if(isEmpty(q))  
        return;
    else
    {
        if(q->size == 1)
        {
            q->front = q->back = nullptr;
            q->size --;
        }
        else
        {
            Node *p = q->back;
            while (p->next != q->front)
            {
                p = p->next;
            }
            q->front = p;
            q->front->next = nullptr;
            q->size--;
        }
    }
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