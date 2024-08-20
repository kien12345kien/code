#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


class Product{
    private:
        char name[20];
        int quantity;
        float price;
    
    public:
        Product(string n = "", int q = 0, float p = 1){
           strcpy(name, n.c_str());
           quantity = q;
           price = p;
        }

        // void printQuantity(){
        //     cout << quantity;
        // }
        
        Product takenProduct(int taken) {
        if (taken <= quantity) {
            quantity -= taken;
            cout << "product left: " << quantity << endl;
            return Product(name, taken, price);
        } 
        
        else 
        {
            cout << "Not enough stock of " << name << endl;
            return Product(name, 0, price);
        }
    }
    
    void printProduct() const {
        cout << "Product: " << name << ", Quantity: " << quantity << ", Price: $" << price << endl;
        // cout << "product left: " <<  << endl;

    }

};

typedef struct Node
{
    Product data;
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

void enqueue(Queue* q, const Product& product) {    //const Product& product
    Node* p = new Node;
    p->data = product;
    p->next = nullptr;
    if (isEmpty(q)) {
        q->top = q->back = p;
    } else {
        q->back->next = p;
        q->back = p;
    }
    q->size++;
}


void dequeue(Queue* q) {
    if (isEmpty(q)) {
        return;
    } else {
        Node* temp = q->top;
        q->top = q->top->next;
        delete temp;
        q->size--;
        if (q->top == nullptr) {
            q->back = nullptr;
        }
    }
}

Product front(Queue* q) {
    if (!isEmpty(q)) {
        return q->top->data;
    }
    return Product(); // Return a default product if queue is empty
}

Product p1("milk", 5, 132);

int main()
{
    // Example usage
    Queue myQueue;
    init(&myQueue);

    enqueue(&myQueue, p1.takenProduct(2));

    enqueue(&myQueue, p1.takenProduct(2));
    enqueue(&myQueue, p1.takenProduct(2));

    while (!isEmpty(&myQueue)) {
            Product p = front(&myQueue);
            cout << "Dequeued: ";
            p.printProduct();
            dequeue(&myQueue);
        }

    return 0;
}