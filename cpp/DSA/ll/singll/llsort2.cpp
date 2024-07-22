#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node* next;
}
Node;

Node* initNode(int val)
{
    Node* node = new Node;
    node->data = val;
    node->next = nullptr;
    return node;
}

typedef struct list
{
    int size;   // Theo dõi số lượng node
    Node *head; // Trỏ tới node đầu tiên
}
List;

void init(List* l)  // Create an empty list
{   
    l->size = 0;    // Đặt số lượng list( == node) ban đầu = 0
    l->head = nullptr;  // list trỏ tới l->head = nullptr
}

int isEmpty(List *l)    // Check of the list is empty
{
    return (l->size == 0);
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
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    List myList;
    init(&myList);
    Node* node1 = initNode(10);
    Node* node2 = initNode(5);
    Node* node3 = initNode(7);
    Node* node4 = initNode(100);

    

    cout << node1->data << endl << node4->data;
}