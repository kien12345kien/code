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

node *initNode(int val) // Tạo node. mới với giá trị  VD: Node* node1 = initNode(10);
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
    }
}

void insert(Node *newNode, Node *ptr, List* l)
//  newNode: a pointer to new node that want to insert
//  ptr: a pointer to a node which you want to insert newNode after it
//  l: a pointer to the linked list
{
    // newNode->next = ptr->next;   // Đéo cần
    ptr->next = newNode;    //ptr’s next pointer is updated to point to the newNode (i.e., ptr->next = newNode)
    l->size++;
}

void remove(List* l, int val)   // Remove an item from a list
{
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

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i){
            swap(arr[min_idx], arr[i]);
            
        }
    }
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
    // insertFirst(&myList, node1);
    // insert(node2, node1, &myList);
    // insert(node3, node2, &myList);

    // Print the list (for demonstration purposes)
    // Node* current = myList.head;
    // while (current != nullptr)
    // {
    //     cout << current->data << " ";
    //     current = current->next;
    // }
    // cout << endl;

    int arr[] = {node1->data, node2->data, node3->data, node4->data};
    int length = sizeof(arr)/ sizeof(arr[0]);

































    // // Remove a node (e.g., remove node with value 20)
    // remove(&myList, 20); // Example of removing node2

    // // Print the updated list
    // current = myList.head;
    // while (current != nullptr)
    // {
    //     cout << current->data << " ";
    //     current = current->next;
    // }
    // cout << endl;

    // // Clean up memory (delete nodes)
    // delete node1;
    // // delete node2;
    // delete node3;

    return 0;
}
