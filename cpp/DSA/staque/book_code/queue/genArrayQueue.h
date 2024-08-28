//********************  ArrayQueue.h  **********************
//             queue implemented as an array
#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include <iostream>
using namespace std;

class ArrayQueue {
public:
    ArrayQueue() : first(-1), last(-1) {
    }
    
    void enqueue(int el);
    int dequeue();
    bool isFull() const {
        return first == 0 && last == size-1 || first == last + 1;
    }
    bool isEmpty() const {
        return first == -1;
    }
    
private:
    static const int size = 100;
    int first, last;
    int storage[size];
};

void ArrayQueue::enqueue(int el) {
    if (!isFull()) {
        if (last == size-1 || last == -1) {
            storage[0] = el;
            last = 0;
            if (first == -1)
                first = 0;
        } else {
            storage[++last] = el;
        }
    } else {
        cout << "Full queue.\n";
    }
}

int ArrayQueue::dequeue() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty.");
    }
    int tmp = storage[first];
    if (first == last) {
        last = first = -1;
    } else if (first == size-1) {
        first = 0;
    } else {
        first++;
    }
    return tmp;
}

#endif
