#include <iostream>
using namespace std;

int search(int a[], int x, int n)
{
    for(int i = 0; i < n; i++)
    {
        if (a[i]==x) return i;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6,30, 60, 100};
    int num = 30;
    int length = sizeof(arr) / sizeof(int);
    search(arr, num, length);
}