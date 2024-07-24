#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


// Khai báo node
typedef struct node
{
    int data;   // Lưu trữ giá trị
    struct node *next;  // Trỏ đến node tiếp theo
}
Node;

// K
typedef struct list
{
    int size;   // Theo dõi số lượng node
    node *head; // Trỏ tới node đầu tiên
}
List;

void init(List* l)  // Create an empty list
{   
    l->size = 0;    // Đặt số lượng list( == node) ban đầu = 0
    l->head = nullptr;  // list trỏ tới l->head = nullptr
}

Node *initNode(int val) // Tạo node. mới với giá trị  VD: Node* node1 = initNode(10);
{
    Node *node = new Node;
    node->data = val;
    node->next = nullptr;
    return node;
}

int isEmpty(List *l)    // Check of the list is empty
{
    return (l->size == 0);
}

void insertFirst(List* l, Node *newNode)
{
    if(isEmpty(l))  // If list is empty
    {
        l->size ++; // Increment the list size
        l->head = newNode;  // Để con trỏ head trỏ tới newNode
        newNode->next = newNode;
    }
}

void insert(Node *newNode, Node *ptr, List* l)
//  newNode: a pointer to new node that want to insert
//  ptr: a pointer to a node which you want to insert newNode after it
//  l: a pointer to the linked list
{
    // newNode->next = ptr->next;   // Đéo cần
    ptr->next = newNode;    //ptr’s next pointer is updated to point to the newNode (i.e., ptr->next = newNode)
    newNode->next = l->head;
    l->size++;
}

void remove(List* l, int val)   // Remove an item from a list
{
    if(isEmpty(l)) {
        cout << "List is empty, nothing to remove." << endl;
        return;
    }

    Node*  p = l->head;
    if(p->data == val)
    {
        l->head = p->next;
        delete p;
        l->size --;
        return;
    }

    Node *q = p->next;
    int cnt = 1;
    while ((p->data!= val) && (cnt < l->size))
    {
        /* code */
        q = p;
        p = p->next;
    }
    if(p!= nullptr)
    {
        q->next = p->next;
        l->size --;
        delete p;
    }
    
}

void printList(List* l) // Function to print the list
{
    if(isEmpty(l)) {
        cout << "List is empty" << endl;
        return;
    }

    Node* p = l->head;
    while(p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    // Create an empty linked list
    List myList;
    init(&myList);

    // Initialize some nodes
    Node* node1 = initNode(64);
    Node* node2 = initNode(25);
    Node* node3 = initNode(12);
    Node* node4 = initNode(22);

    insertFirst(&myList, node1);
    insert(node2, node1, &myList);
    insert(node3, node2, &myList);
    insert(node4, node3, &myList);

    cout << "List before removal: ";
    printList(&myList);

    remove(&myList, 25);

    cout << "List after removal: ";
    printList(&myList);

    return 0;
}