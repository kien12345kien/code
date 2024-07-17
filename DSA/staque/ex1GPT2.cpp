#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
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

    string getName() const {
        return string(name);
    }

    bool purchase(int qty) {
        if (qty <= quantity) {
            quantity -= qty;
            cout << qty << " " << name << "(s) purchased. Remaining quantity: " << quantity << endl;
            return true;
        } else {
            cout << "Not enough stock of " << name << ". Purchase failed." << endl;
            return false;
        }
    }

    void printProduct() const {
        cout << "Product: " << name << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }
};
class Customer {
public:
    int id;
    int purchaseQuantity;

    Customer(int i = 0, int qty = 0) : id(i), purchaseQuantity(qty) {}
};

typedef struct Node {
    Customer data;
    Node* next;
}Node;

typedef struct Queue {
    Node* front;
    Node* back;
    int size;

    Queue() : front(nullptr), back(nullptr), size(0) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(const Customer& customer) {
        Node* newNode = new Node();
        newNode->data = customer;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) return;
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
        if (front == nullptr) {
            back = nullptr;
        }
    }

    Customer frontCustomer() {
        if (!isEmpty()) {
            return front->data;
        }
        return Customer(); // Return a default customer if queue is empty
    }
}
Queue;

int main() {
    // Example usage
    Product p1("Milk", 10, 1.5);

    Queue customerQueue;
    
    // Adding customers with different purchase quantities
    customerQueue.enqueue(Customer(1, 2));
    customerQueue.enqueue(Customer(2, 3));
    customerQueue.enqueue(Customer(3, 5));
    customerQueue.enqueue(Customer(4, 1));

    while (!customerQueue.isEmpty()) {
        Customer currentCustomer = customerQueue.frontCustomer();
        cout << "Customer " << currentCustomer.id << " attempting to purchase " << currentCustomer.purchaseQuantity << " " << p1.getName() << "(s)." << endl;
        p1.purchase(currentCustomer.purchaseQuantity);
        customerQueue.dequeue();
    }

    return 0;
}
