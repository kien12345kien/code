#include <iostream>
using namespace std;

// Find the index of the minimum element in the array
int minIndex(int arr[], int i, int j) {
    if (i == j)
        return i;
    
    int k = minIndex(arr, i + 1, j);
    return (arr[i] < arr[k]) ? i : k;
}

// Recursive selection sort
void recurSelectionSort(int arr[], int n, int index = 0) {
    if (index == n)
        return;

    // Find the minimum element's index in the remaining unsorted part
    int k = minIndex(arr, index, n - 1);

    // Swap the minimum element with the current element
    if (k != index)
        swap(arr[k], arr[index]);

    // Recur for the next index
    recurSelectionSort(arr, n, index + 1);
}

int main() {
    int arr[] = {3, 1, 5, 2, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    recurSelectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
