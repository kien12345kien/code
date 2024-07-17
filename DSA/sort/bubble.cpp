#include <iostream>

using namespace std;

void bubble(int data[], int n){
    for(int i = 0; i < n-1; i++)
        for(int j = n-1; j > i; --j)
            if (data[j] < data[j-1])
                swap(data[j], data[j-1]);
}

int main(){
    int arr[] = {5,3,8,4,9,2,0,3};
    int length = sizeof(arr)/sizeof(arr[0]);
    
    bubble(arr, length);

    cout << "sorted array: " << endl;
    for(int i = 0; i < length; i ++){
        cout << arr[i];
    }
}