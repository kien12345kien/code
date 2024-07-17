#include <iostream>
using namespace std;

int max(int arr[], int first, int last);

int main()
{
    int myArray[] = {10, 50, 20};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);
    cout << arraySize;

    int result = max(myArray, 0, 3);
    cout << "The maximum value in the array is: " << result << endl;

    return 0;
}

int max(int arr[], int first, int last)
// first: thứ tự của số đầu tiên trong bảng
// last: thứ tự của số cuối cùng trong bảng

{
    if(first == last)
    {
        return arr[first];
    }

    int mid = first + (last - first)/2;
    int a = max(arr, first, mid);
    int b = max(arr, mid+1, last);
    if(a<b) return b;
    return a;
}