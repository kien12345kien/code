// function factori(num, factor)
// if num <= 1  return
// if num%factor == 0
// print factor
// factori(num/factor, factor)
// else
// increment current_factor
// factori(num, factor)

#include <iostream>
using namespace std;

void factory(int num, int factor){
    if(num < 2 )    return;

    if(num % factor == 0){
        cout << factor << endl;
        factory(num/factor, factor);
    }

    else{
        factor ++;
        factory(num, factor);
    }
}

int main(){
    int num = 200000000;
    factory(num, 2);
}