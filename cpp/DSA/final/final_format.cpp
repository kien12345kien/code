#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

// void centered_cube(int n){
//     if(n < 1)   return;
//     int function = pow(n, 3) + pow((n + 1), 3);
//     std::cout << function <<std::endl;
//     centered_cube(n-1);
// }

// int main(){
//     int n = 4;
//     centered_cube(n);
//     return 0;
// }

int rec_num(int number){
    int sum = 0;
    while (number > 0){
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
int main(){
    int number = 92349294;
    int result = rec_num(number);
    cout << result;
}