#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    // Constructor
    LinkedList() : head(nullptr), size(0) {}

    // Destructor
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Insert a node at the beginning
    void insertFirst(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Insert a node after a given node
    void insertAfter(Node* prevNode, int val) {
        if (prevNode == nullptr) {
            cout << "Previous node cannot be null" << endl;
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        size++;
    }

    // Remove a node by value
    void remove(int val) {
        Node* temp = head;
        Node* prev = nullptr;

        // If head node itself holds the key to be deleted
        if (temp != nullptr && temp->data == val) {
            head = temp->next;
            delete temp;
            size--;
            return;
        }

        // Search for the key to be deleted, keep track of the
        // previous node as we need to change 'prev->next'
        while (temp != nullptr && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }

        // If the key was not present in the linked list
        if (temp == nullptr) return;

        // Unlink the node from linked list
        prev->next = temp->next;
        delete temp;
        size--;
    }

    // Print the linked list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Get the size of the linked list
    int getSize() {
        return size;
    }
};

int main() {
    LinkedList myList;

    // Insert nodes into the list
    myList.insertFirst(10);
    Node* node1 = myList->head;
    myList.insertAfter(node1, 20);
    Node* node2 = node1->next;
    myList.insertAfter(node2, 30);

    // Print the list
    cout << "Original list: ";
    myList.printList();

    // Remove a node
    myList.remove(20);

    // Print the updated list
    cout << "Updated list: ";
    myList.printList();

    return 0;
}
