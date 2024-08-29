//**********************  Queue.h  *************************
//     queue implemented with doubly linked list
#ifndef DLL_QUEUE
#define DLL_QUEUE

#include <list>
#include <stdexcept>

class Queue {
public:
    Queue() {
    }
    
    void clear() {
        lst.clear();
    }
    
    bool isEmpty() const {
        return lst.empty();
    }
    
    int& front() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty.");
        }
        return lst.front();
    }
    
    int dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty.");
        }
        int el = lst.front();
        lst.pop_front();
        return el;
    }
    
    void enqueue(const int& el) {
        lst.push_back(el);
    }
    
private:
    std::list<int> lst;
};

#endif
