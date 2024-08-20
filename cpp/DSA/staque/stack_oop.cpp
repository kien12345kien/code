#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    int size;
    Node* top;

public:
    Stack() : size(0), top(nullptr) {}

    bool isEmpty() const {
        return size == 0;
    }

    bool push(int newData) {
        Node* p = new Node(newData);
        if (p == nullptr) return false;

        p->next = top;
        top = p;
        size++;
        return true;
    }

    bool pop() {
        if (isEmpty()) return false;

        Node* p = top;
        top = top->next;
        size--;
        delete p;
        return true;
    }

    void printStack() const {
        Node* temp = top;
        while (temp != nullptr) {
            cout << "Popped: " << temp->data << endl;
            temp = temp->next;
        }
    }

    Node* getTop() const {
        return top;
    }
};

int main() {
    Stack myStack;

    myStack.push(64);
    myStack.push(25);
    myStack.push(12);
    myStack.push(22);

    while (!myStack.isEmpty()) {
        cout << "Popped: " << myStack.getTop()->data << endl;
        myStack.pop();
    }

    return 0;
}
