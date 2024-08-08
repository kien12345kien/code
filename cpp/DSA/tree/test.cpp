 #include <iostream>
#include <string>
#include <cstdlib>

#define NONE nullptr

using namespace std;


// Khai báo node
typedef struct node
{
    int data;   // Lưu trữ giá trị
    struct node *next1;  // Trỏ đến node tiếp theo
    struct node *next2;  // Trỏ đến node tiếp theo
}
Node;

// K
typedef struct list
{
    int size;   // Theo dõi số lượng node
    node *head; // Trỏ tới node đầu tiên
}
GrDot;

void init(GrDot* l)  // Create an empty list
{   
    l->size = 0;    // Đặt số lượng list( == node) ban đầu = 0
    l->head = nullptr;  // list trỏ tới l->head = nullptr
}

Node *initNode(int val) // Tạo node. mới với giá trị  VD: Node* node1 = initNode(10);
{
    Node *node = new Node;
    node->data = val;
    node->next1 = nullptr;
    node->next2 = nullptr;
    return node;
}

int isEmpty(GrDot *l)    // Check of the list is empty
{
    return (l->size == 0);
}

void insertFirst(GrDot* l, Node *newNode)
{
    if(isEmpty(l))  // If list is empty
    {
        l->size ++; // Increment the list size
        l->head = newNode;  // Để con trỏ head trỏ tới newNode
    }
}

void insert(Node *newNode1, Node *newNode2, Node *ptr, GrDot* l)
//  newNode: a pointer to new node that want to insert
//  ptr: a pointer to a node which you want to insert newNode after it
//  l: a pointer to the linked list
{
    // newNode->next = ptr->next;   // Đéo cần
    ptr->next1 = newNode1;    //ptr’s next pointer is updated to point to the newNode (i.e., ptr->next = newNode)
    l->size++;
    ptr->next2 = newNode2;
    l->size++;
    (newNode1 == nullptr || newNode2 == nullptr) ? (l->size --) : (l->size = l->size);
}

// void remove(GrDot* l, int val)   // Remove an item from a list
// {
//     Node*  p = l->head;
//     if(p->data == val)
//     {
//         l->head = p->next1;
//         delete p;
//         l->size --;
//         return;
//     }

//     Node *q = p->next1;
//     int cnt = 1;
//     while ((p->data!= val) && (cnt < l->size))
//     {
//         /* code */
//         q = p;
//         p = p->next1;
//     }
//     if(p!= nullptr)
//     {
//         q->next1 = p->next1;
//         l->size --;
//         delete p;
//     }
    
// }

void printList(GrDot* l) // Function to print the list
{
    Node* p = l->head;
    while(p != nullptr)
    {
        cout << p->data << " ";
        p = p->next1;
    }
    cout << endl;
}

int main()
{
    // Create an empty linked list
    GrDot myList;
    init(&myList);

    // Initialize some nodes
    Node* a = initNode(1);
    Node* b = initNode(2);
    Node* c = initNode(3);
    Node* d = initNode(4);
    Node* e = initNode(5);
    Node* f = initNode(6);
    Node* g = initNode(7);


    insertFirst(&myList, a);
    insert(c, b, a, &myList);
    insert(d, NONE, c, &myList);
    insert(f, NONE, d, &myList);
    insert(d, c, b, &myList);
    insert(e, NONE, d, &myList);

    cout << "List before removal: ";
    printList(&myList);

    // remove(&myList, 25);

    cout << "List after removal: ";
    printList(&myList);

    return 0;
}%                                                                                         phamtunganh@hello-2 singll % 
