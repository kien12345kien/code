#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNode{
public:
    IntSLLNode(){
        next = 0;
    }
    IntSLLNode(int el, IntSLLNode* ptr = 0){
        info = el; next = ptr;
    }
    int info;
    IntSLLNode* next;
};

class intSLList
{
    private:
        IntSLLNode* head, *tail;
    public:
        intSLList(){
            head = tail = 0;
        }
        ~intSLList();

        int isEmpty(){
            return head == 0;
        }
        void addToHead(int);
        void addToTail(int);
        int deleteFromHead();
        int deleteFromTail();
        void deleteNode(int);
        bool isInList(int) const;
};

#endif