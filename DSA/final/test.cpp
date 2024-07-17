// #include <iostream>
// using namespace std;

// void findTriplets(int arr[], int n) 
// {
//     for (int i = 0; i < n - 2; i++) 
//     {
//         for (int j = i + 1; j < n - 1; j++) 
//         {
//             for (int k = j + 1; k < n; k++) 
//             {
//                 if (arr[i] * arr[j] == arr[k] || arr[j] * arr[k] == arr[i] || arr[k] * arr[i] == arr[j]) 
//                 {
//                     cout << "(" << arr[i] << ", " << arr[j] << ", " << arr[k] << ")" << endl;
//                 }
//             }
//         }
//     }
// }

// int main() {
//     int arr[] = {4, 15, 45, 9, 40, 27, 3, 5, 10};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Triplets where one number is the product of the other two:" << endl;
//     findTriplets(arr, n);

//     return 0;
// }


#include <iostream>
using namespace std;

bool isTriplet(int a, int b, int c) {
    return (a * b == c) || (b * c == a) || (c * a == b);
}

void findTripletsRec(int arr[], int n, int i, int j, int k) {
    if (i >= n - 2) {
        return; // Base case: Stop when we've checked all combinations
    }

    if (k >= n) {
        // Move to the next pair (i, j)
        findTripletsRec(arr, n, i, j + 1, j + 2);
        return;
    }

    if (isTriplet(arr[i], arr[j], arr[k])) {
        cout << "(" << arr[i] << ", " << arr[j] << ", " << arr[k] << ")" << endl;
    }

    // Recurse with the same pair (i, j) and move to the next k
    findTripletsRec(arr, n, i, j, k + 1);
}

void findTriplets(int arr[], int n) {
    findTripletsRec(arr, n, 0, 1, 2);
}

int main() {
    int arr[] = {4, 15, 45, 9, 40, 27, 3, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Triplets where one number is the product of the other two:" << endl;
    findTriplets(arr, n);

    return 0;
}
