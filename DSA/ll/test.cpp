#include <iostream>
#include <string>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}
Node;

typedef struct list
{
	int size;
	node* head;
}
List;

void init(List* l)
{
	l->size = 0;
	l->head = nullptr;
}
int main()
{

}