#include "intSLList.h"
#include <iostream>

using namespace std;


IntSLList:: ~IntSLList(){
    for(IntSLLNode* p; !isEmpty();){
        p = head->next;
        delete head;
        head = p;
    }
}
void IntSLList::addToHead(int el){
    head = new IntSLLNode(el, head);
    if(tail == 0){
        tail = head;
    }
}
void IntSLList::addToTail(int el) {
    if (tail != 0) {    // if list not empty;
        tail->next = new IntSLLNode(el);
        tail = tail->next;
}
    else head = tail = new IntSLLNode(el);
}

int IntSLList::deleteFromHead() {
    int el = head->info;
    IntSLLNode *tmp = head;
    if (head == tail)   // if only one node in the list;
        head = tail = 0;
    else head = head->next;
    delete tmp;
    return el;
}
int IntSLList::deleteFromTail() {
    int el = tail->info;
    if (head == tail) { // if only one node in the list;
    delete head;
    head = tail = 0;

    }
    else {              // if more than one node in the list,
        IntSLLNode *tmp;  // find the predecessor of tail;
        for(tmp = head; tmp->next != tail; tmp = tmp->next);
        delete tail;
        tail = tmp;    // the predecessor of tail becomes tail;
        tail->next = 0;
    }
    return el; 
}

void IntSLList::deleteNode(int el){
    if(head != 0){
        if(head == tail && el == head->info){
            delete head;
            head = tail = 0;
        }
        else if(el == head->info){
            IntSLLNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        else{
            IntSLLNode* pred, *tmp;
            for(pred = head, tmp = head->next; tmp != 0 && !(tmp->info == el); pred = pred->next, tmp = tmp->next);
            if(tmp != 0){
                pred->next = tmp->next;
                if(tmp == tail)
                    tail = pred;
                delete tmp;
            }
        }
    } 
}

bool IntSLList::isInList(int el) const{
    IntSLLNode* tmp;
    for(tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return tmp != 0;
}

int main() {
    IntSLList list;

    // Test isEmpty
    cout << "Is the list empty? " << (list.isEmpty() ? "Yes" : "No") << endl;

    // Test addToHead
    list.addToHead(10);
    list.addToHead(20);
    list.addToHead(30);

    // Test addToTail
    list.addToTail(40);
    list.addToTail(50);

    // Test isEmpty after adding elements
    cout << "Is the list empty after adding elements? " << 
        (list.isEmpty() ? "Yes" : "No") << endl;

    // Test isInList
    cout << "Is 20 in the list? " << (list.isInList(20) ? "Yes" : "No") << endl;
    cout << "Is 60 in the list? " << (list.isInList(60) ? "Yes" : "No") << endl;

    // Test deleteFromHead
    cout << "Deleted from head: " << list.deleteFromHead() << endl;

    // Test deleteFromTail
    cout << "Deleted from tail: " << list.deleteFromTail() << endl;

    // Test deleteNode
    list.deleteNode(20);
    cout << "Deleted node with value 20. Is 20 still in the list? " << (list.isInList(20) ? "Yes" : "No") << endl;

    // Clean up
    while (!list.isEmpty()) {
        cout << "Deleted from head: " << list.deleteFromHead() << endl;
    }

    cout << "Is the list empty after deleting all elements? " << (list.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}