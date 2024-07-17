#include <iostream>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;

void select(int a[], int n){
    int i, j, min;
    for(i = 0; i < n-1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(a[j] < a[min])   min = j;
        }
        swap(a[min], a[i]);
    }
}

int main(){
    int arr[] = {5,3,8,4,9,2,0,3};
    int length = sizeof(arr)/sizeof(arr[0]);
    
    select(arr, length);

    cout << "sorted array: " << endl;
    for(int i = 0; i < length; i ++){
        cout << arr[i];
    }

    return 0;
}