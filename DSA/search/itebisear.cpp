#include <iostream>

int bsearch(int a[], int sizez, int x)
{
    int low = 0, high = sizez -1;
    while (low <= high)
    {
        int mid = (low+high)/2;
        
        if(x < a[mid])
            high = mid - 1;
        else if(x > a[mid])
            low = mid + 1;    
        else
            return mid;
    }
    return -1;
    
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int length = sizeof(arr) / sizeof(arr[1]);
    std::cout << length;
    int num = 1;
    int result = bsearch(arr, length, num);

        if (result != -1) {
        std::cout << "Element " << num << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << num << " not found in the array." << std::endl;
    }
}