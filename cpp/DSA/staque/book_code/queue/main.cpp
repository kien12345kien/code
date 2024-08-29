#include <iostream>
#include "genArrayQueue.h" // For the array-based queue
#include "genQueue.h"      // For the list-based queue

using namespace std;

int main() {
    // Testing ArrayQueue
    cout << "Testing ArrayQueue:" << endl;
    ArrayQueue arrayQueue;
    
    // Enqueue elements
    for (int i = 1; i <= 5; ++i) {
        cout << "Enqueueing " << i << " into ArrayQueue" << endl;
        arrayQueue.enqueue(i);
    }
    
    // Dequeue elements
    while (!arrayQueue.isEmpty()) {
        cout << "Dequeued from ArrayQueue: " << arrayQueue.dequeue() << endl;
    }
    
    // Attempt to dequeue from empty queue
    try {
        cout << "Attempting to dequeue from empty ArrayQueue:" << endl;
        arrayQueue.dequeue();
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    // Testing Queue
    cout << "\nTesting Queue:" << endl;
    Queue linkedQueue;
    
    // Enqueue elements
    for (int i = 1; i <= 5; ++i) {
        cout << "Enqueueing " << i << " into Queue" << endl;
        linkedQueue.enqueue(i);
    }
    
    // Dequeue elements
    while (!linkedQueue.isEmpty()) {
        cout << "Dequeued from Queue: " << linkedQueue.dequeue() << endl;
    }
    
    // Attempt to dequeue from empty queue
    try {
        cout << "Attempting to dequeue from empty Queue:" << endl;
        linkedQueue.dequeue();
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
