#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val): data(val), next(nullptr) {};
};

class Queue{
    private:
        int size;
        Node *front, *back;

    public:
        Queue() : size(0), front(nullptr), back(nullptr) {}

        bool isEmpty() const{
            return (size == 0 && front == nullptr);
        }

        void enqueue(int val){
            Node *p = new Node(val);
            p->data = val;
            p->next = nullptr;

            (front == nullptr) ? (front = back = p) : (back->next = p, back = p);

            size ++;
        }

        void dequeue(){
            if(isEmpty())   return;

            Node *temp = front;
            front = front->next;

            if(front == nullptr)    back = nullptr;

            delete temp;
            size --;
        }

        int frontValue() const{
            if (!isEmpty()) return front->data;
            
            throw runtime_error("Queue is empty");
        }

        void printQueue() const{
            Node* p = front;
            while (p != nullptr){
                cout << p->data << " ";
                p = p->next;
            }

            cout << endl;
        }

};

int main() {
    Queue myQueue;

    myQueue.enqueue(64);
    myQueue.enqueue(25);
    myQueue.enqueue(12);
    myQueue.enqueue(22);

    cout << "Initial Queue: ";
    myQueue.printQueue(); // To visualize the queue

    while(!myQueue.isEmpty()){
        cout << "Dequeued: " << myQueue.frontValue() << endl;
        myQueue.dequeue();
    }


    return 0;
}