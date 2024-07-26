#include<iostream>

using namespace std;

int x;

int main(){
    int x = 10;
    cout << ::x << endl;
    cout << x << endl;
    return 0;
}