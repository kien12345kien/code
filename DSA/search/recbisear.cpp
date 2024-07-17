#include <iostream>
using namespace std;

int rbsearch(int a[], int firstp, int lastp, int x)
{
    if(firstp > lastp)      

        return -1;
    int mid = (firstp + lastp) / 2;

    if(x < a[mid])  
        return rbsearch(a, firstp, mid-1, x);

    else if (x > a[mid])    
        return rbsearch(a, mid+1, lastp, x);
        
    else    
        return mid;
}

int main() {
    // Example usage:
    int arr[] = {1, 3, 5, 7, 9};
    int length = sizeof(arr) / sizeof(arr[0]);
    int numb = 5;
    int result = rbsearch(arr, 0, length - 1, numb);

    if (result != -1) {
        std::cout << "Element " << numb << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << numb << " not found in the array." << std::endl;
    }

    return 0;
}