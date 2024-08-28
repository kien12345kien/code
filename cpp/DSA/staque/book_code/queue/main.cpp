#include <iostream>
#include "arrayQueue.h"
#include "queue.h"

using namespace std;

int main() {
    // Test arrayQueue
    cout << "Testing arrayQueue:" << endl;

    // Create an arrayQueue of integers with a size of 5
    arrayQueue<int, 5> arrQueue;

    // Enqueue some elements
    arrQueue.enqueue(1);
    arrQueue.enqueue(2);
    arrQueue.enqueue(3);

    // Dequeue and display elements
    cout << "Dequeued from arrayQueue: " << arrQueue.dequeue() << endl; // Should output 1
    cout << "Dequeued from arrayQueue: " << arrQueue.dequeue() << endl; // Should output 2

    // Check if the queue is empty
    if (arrQueue.isEmpty()) {
        cout << "arrayQueue is empty." << endl;
    } else {
        cout << "arrayQueue is not empty." << endl;
    }

    // Enqueue more elements
    arrQueue.enqueue(4);
    arrQueue.enqueue(5);
    arrQueue.enqueue(6);

    // Check if the queue is full
    if (arrQueue.isFull()) {
        cout << "arrayQueue is full." << endl;
    } else {
        cout << "arrayQueue is not full." << endl;
    }

    // Dequeue and display remaining elements
    cout << "Dequeued from arrayQueue: " << arrQueue.dequeue() << endl; // Should output 3
    cout << "Dequeued from arrayQueue: " << arrQueue.dequeue() << endl; // Should output 4

    // Test Queue with std::list
    cout << "Testing Queue (std::list):" << endl;

    // Create a Queue of integers
    Queue<int> listQueue;

    // Enqueue some elements
    listQueue.enqueue(10);
    listQueue.enqueue(20);
    listQueue.enqueue(30);

    // Dequeue and display elements
    cout << "Dequeued from listQueue: " << listQueue.dequeue() << endl; // Should output 10
    cout << "Dequeued from listQueue: " << listQueue.dequeue() << endl; // Should output 20

    // Check if the queue is empty
    if (listQueue.isEmpty()) {
        cout << "listQueue is empty." << endl;
    } else {
        cout << "listQueue is not empty." << endl;
    }

    // Enqueue more elements
    listQueue.enqueue(40);
    listQueue.enqueue(50);

    // Display the front element
    cout << "Front of listQueue: " << listQueue.front() << endl; // Should output 30

    // Dequeue and display remaining elements
    cout << "Dequeued from listQueue: " << listQueue.dequeue() << endl; // Should output 30
    cout << "Dequeued from listQueue: " << listQueue.dequeue() << endl; // Should output 40
    cout << "Dequeued from listQueue: " << listQueue.dequeue() << endl; // Should output 50

    return 0;
}
