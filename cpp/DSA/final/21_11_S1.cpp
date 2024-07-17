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

void factori(int num, int factor){
    if (num <= 1)
    {
        return;
    }
    
    if (num % factor == 0)
    {
        cout << factor << endl;
        factori(num / factor, factor);
    }
    else{
        factor ++;
        factori(num, factor);
    }
    
    
}

int main(){
    int x = 278342368;
    factori(x, 2);
}
