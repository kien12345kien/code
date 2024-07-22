#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void printVector(char* s, const vector<int> & v){
    cout << s << " = (" ;
    if(v.size()== 0)
    {
        cout << ")\n";
        return;
    }
    vector<int>::const_iterator i = v.begin();
    for(; i != v.end() - 1; i++)    cout << *i << ' ';
    cout << *i << ")\n";
}

bool f1(int n){
    return n < 4;
}

int main(){
    int a[] = {1,2,3,4,5};
}