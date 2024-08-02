#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val): data(val), next(nullptr) {};
};

class List{
    private:
        int size;
        Node* head;

    public:
        List() : size(0), head(nullptr) {}

        bool isEmpty() const{
            return (size == 0);
        }

        void insertFirst(Node* newNode){
            if(isEmpty()){
                size ++;
                head = newNode;
            }
        }

        void insert(Node* newNode, Node* ptr){
            newNode->next = ptr->next;
            ptr->next = newNode;
            size++;
        }

        void remove(int val){
            if (head == nullptr)    return;

            Node* p = head;
            if (p->data == val){
                head = p->next;
                delete p;
                size --;
                return;
            }
            Node* q = p;
            p = p->next;
            while(p != nullptr && p->data != val){
                q = p;
                p = p->next;
                delete p;
                size --;
            }
        }

        void printList() const{
            Node* p = head;
            while (p != nullptr){
                p = p->next;
            }
            cout << endl;
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