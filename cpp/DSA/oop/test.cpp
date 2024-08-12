#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string str = "dsf fdsfds adasd xzcxz gfh frejfo";
    int i, j = 0;

    for(i = 0; i < str.length(); i++){

        if (i == 0 && str[i] != ' '){
            cout << str[i];
        }

        else if (i > 0 && str[i-1] == ' '){
            cout << str[i];
        }
        
    }
}