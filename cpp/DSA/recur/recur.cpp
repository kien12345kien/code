#include <iostream>
using namespace std;

int fibo(int a){
    if ((a == 0) || (a == 1))
    {
        return a;
    }
    return fibo(a-1) + fibo(a-2);
    
}
int main()
{
    int n = 9;
    cout << fibo(n);
}