#include <iostream>

using namespace std;

void insert(int data[], int n){
    int i, j;
    for(i = 1;i < n; i++){
        int tmp = data[i];
        for(j = i; j > 0 && tmp < data[j-1]; j --)
            data[j] = data[j-1];
        data[j] = tmp;
    }
}

int main(){
    int arr[] = {6,3,7,2,5,3,9,0};
    int length = sizeof(arr)/sizeof(arr[1]);

    insert(arr, length);

    cout << "sorted array: " << endl;
    for(int i = 0; i < length; i ++){
        cout << arr[i];
    }
}