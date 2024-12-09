#include <iostream>
// #include <cstdio>

using namespace std;

void multipl(int a, int b){
    int final;
    for(a = 0; a < 10; a++){
        for(b = 0; b < 10; b++){
            // final = a * b;
            cout << a << " * " << b << " = " << (a * b) << endl;

        }
    }
    
}

int main(){
    multipl(0, 10);
    FILE* file = fopen("example.txt", "a");

    if(file == nullptr){
        std::cerr << "Error opening file";
        return 1;
    }

    // fprintf(file, "hello");

    // fprintf(file, "%s", content);

    fclose(file);

    return 0;

    
}