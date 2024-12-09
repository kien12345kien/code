#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    FILE* fptr = fopen("hello.txt", "a");
    if(fptr == nullptr){
        cerr << "Not Found!" << endl;
        return 1;
    }

    fprintf(fptr, "my favour");

    fclose(fptr);

    return 0;
}