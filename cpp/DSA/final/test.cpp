#include <iostream>

using namespace std;

void pentagon(int n){
    int f = (3*n*n - n)/ 2;
    if(n < 1)   return;
    cout << f << endl;
    pentagon(n-1);
}

int main(){
    int num = 9;
    pentagon(num);
}