#include <pthread.h>

void* ALL_IS_OK = (void*)123456789L;
char* mess[2] = {"thread1", "thread2"};
void* writer (void* arg)
{
	int i, j;
	for(i = 0; i < 10)
}