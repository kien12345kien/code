#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

class Product {
    private:
        char name[20];
        int quantity;
        float price;

    public:
        Product(string n = "", int q = 0, float p = 0.0) {
            strcpy(name, n.c_str());
            quantity = q;
            price = p;
        }

        int purchase(int takeNum) {
            if (takeNum <= quantity) {
                quantity -= takeNum;
                cout << takeNum << " " << name << "(s) purchased. Remaining quantity: " << quantity << endl;
                return 1;
            } else {
                cout << "Not enough stock of " << name << ". Purchase failed." << endl;
                return 0;
            }
        }

        void printProduct() {
            cout << "Product: " << name << ", Quantity: " << quantity << ", Price: $" << price << endl;
        }

        const char* getName() {
            return name;
        }
};

class Customer{
    private:
        int id;
        int purchaseQuantity;

    public:
        Customer(int i = 0, int takeNum) : id(i), purchaseQuantity(takeNum){}


        int getId() const {
            return id;
        }

        int getPurchaseQuantity() const {
            return purchaseQuantity;
        }
};

typedef struct Node{
    Customer data;
    Node* next;

};

typedef struct Queue{
    Node* top,* back;
    int size;
};

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

void enqueue(Queue *q, const Customer& customer){
    Node* newNode = new Node;
    newNode->data = customer;
    newNode->next = nullptr;
    if(isEmpty(q)){
        q->back = q->top = newNode;
    }
    else{
        newNode->next = q->back;
        q->back = newNode;
    }
    q->size ++;
};

void dequeue(Queue* q) {
    if (isEmpty(q)) return;
    Node* temp = q->top;
    q->top = q->top->next;
    if (q->top == nullptr) {
        q->back = nullptr;
    }
    delete temp;
    q->size--;
}

Customer frontCustomer(Queue* q) {
        if (!isEmpty(q)) {
            return q->top->data;
        }
        return Customer(); // Return a default customer if queue is empty
};

int main(){
     Product p1("Milk", 10, 1.5);

    Queue customerQueue;
    
    // Adding customers with different purchase quantities
    enqueue(&customerQueue, Customer(1, 2));
    enqueue(&customerQueue, Customer(2, 3));
    enqueue(&customerQueue, Customer(3, 5));
    enqueue(&customerQueue, Customer(4, 1));

    while (isEmpty(&customerQueue)) {
        Customer currentCustomer = frontCustomer(&customerQueue);
        cout << "Customer " << currentCustomer.getId() << " attempting to purchase " << currentCustomer.getPurchaseQuantity() << " " << p1.getName() << "(s)." << endl;
        p1.purchase(currentCustomer.getPurchaseQuantity());
        dequeue(&customerQueue);
    }

    return 0;
}
