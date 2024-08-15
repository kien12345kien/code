#include <iostream>

using namespace std;

class Node{
    public:
        // Declair variables
        int data;
        Node* next;

        //Set variables with values
        Node(int val): data(val), next(nullptr) {}; 
};

class List{
    private:
        int size;
        Node* head;

    public:
        List() : size(0), head(nullptr) {}

        bool isEmpty() const{       //Check whether List is empty or not
            return (size == 0);
        }

        //Insert first node to the list
        void insertFirst(Node* newNode){
            if(isEmpty()){
                size ++;
                head = newNode;     //Update head pointer is newNode
            }  
        }

        //Insert following node
        void insert(Node* newNode, Node* ptr){
            newNode->next = ptr->next;      //Update with every node inserted, the next pointer is equal to the next pointer of previous node
            ptr->next = newNode;            //Update next pointer is newNode
            size++;
        }

        void remove(int val){
            //Check list is empty
            if (head == nullptr)    return;

            Node* p = head;
            if (p->data == val){
                head = p->next;
                delete p;
                size --;
                return;
            }

            // Initialize a pointer to keep track of the previous node
            Node* q = p;
            p = p->next;
            // Traverse the list to find the node with the value val    
            while(p != nullptr && p->data != val){
                q = p;
                p = p->next;
            }

            // If p is nullptr, val was not found in the list
            if(p == nullptr) return;

            // Update the next pointer of q to skip the node p
            q->next = p->next;
            delete p;
            size--;
        }

        void printList() const{
            Node* p = head;
            while (p != nullptr){
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }

        //The destructor is designed to clean up all dynamically allocated nodes in the list to avoid memory leaks.
        ~List() {
            // While the list is not empty
            while (!isEmpty()) {
                // Remove the node at the head (which will delete the node)
                remove(head->data);
            }
        }
};

int main() {
    // Create an empty linked list
    List myList;

    // Initialize some nodes
    Node* node1 = new Node(64);
    Node* node2 = new Node(25);
    Node* node3 = new Node(12);
    Node* node4 = new Node(22);

    myList.insertFirst(node1);
    myList.insert(node2, node1);
    myList.insert(node3, node2);
    myList.insert(node4, node3);

    cout << "List before removal: ";
    myList.printList();

    myList.remove(25);

    cout << "List after removal: ";
    myList.printList();

    return 0;
}