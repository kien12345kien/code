#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Khai báo node
typedef struct node
{
    int data;         // Lưu trữ giá trị
    struct node *next;  // Trỏ đến node tiếp theo
    struct node *prev;  // Trỏ đến node trước đó
} Node;

// Khai báo list
typedef struct list
{
    int size;   // Theo dõi số lượng node
    Node *head; // Trỏ tới node đầu tiên
    Node *tail; // Trỏ tới node cuối cùng
} List;

void init(List* l)  // Create an empty list
{   
    l->size = 0;        // Đặt số lượng list( == node) ban đầu = 0
    l->head = nullptr;  // list trỏ tới l->head = nullptr
    l->tail = nullptr;  // list trỏ tới l->tail = nullptr
}

Node *initNode(int val) // Tạo node. mới với giá trị  VD: Node* node1 = initNode(10);
{
    Node *node = new Node;
    node->data = val;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

int isEmpty(List *l)    // Check if the list is empty
{
    return (l->size == 0);
}

void insertFirst(List* l, Node *newNode)
{
    if(isEmpty(l))  // If list is empty
    {
        l->size ++; // Increment the list size
        l->head = newNode;  // Để con trỏ head trỏ tới newNode
        l->tail = newNode;  // Để con trỏ tail trỏ tới newNode
    }
    else
    {
        newNode->next = l->head; // Liên kết newNode với head hiện tại
        l->head->prev = newNode; // Liên kết head hiện tại với newNode
        l->head = newNode;       // Cập nhật head mới
        l->size ++;              // Tăng kích thước danh sách
    }
}

void insertAfter(Node *newNode, Node *ptr, List* l)
//  newNode: a pointer to new node that want to insert
//  ptr: a pointer to a node which you want to insert newNode after it
//  l: a pointer to the linked list
{
    if(ptr->next == nullptr) // Nếu ptr là node cuối cùng
    {
        ptr->next = newNode;
        newNode->prev = ptr;
        l->tail = newNode;   // Cập nhật tail mới
    }
    else
    {
        newNode->next = ptr->next;
        newNode->prev = ptr;
        ptr->next->prev = newNode;
        ptr->next = newNode;
    }
    l->size++;
}

void remove(List* l, int val)   // Remove an item from a list
{
    Node* p = l->head;
    while (p != nullptr && p->data != val)
    {
        p = p->next;
    }

    if (p == nullptr) // Không tìm thấy giá trị cần xóa
        return;

    if (p == l->head)
    {
        l->head = p->next;
        if (l->head != nullptr)
            l->head->prev = nullptr;
        else
            l->tail = nullptr; // Danh sách trở nên rỗng
    }
    else if (p == l->tail)
    {
        l->tail = p->prev;
        l->tail->next = nullptr;
    }
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    delete p;
    l->size--;
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

    // Insert nodes into the list
    insertFirst(&myList, node1);
    insertAfter(node2, node1, &myList);
    insertAfter(node3, node2, &myList);
    insertAfter(node4, node3, &myList);

    // Print the list (for demonstration purposes)
    Node* current = myList.head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Remove a node (e.g., remove node with value 25)
    remove(&myList, 25);

    // Print the updated list
    current = myList.head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up memory (delete nodes)
    while (!isEmpty(&myList)) {
        remove(&myList, myList.head->data);
    }

    return 0;
}
