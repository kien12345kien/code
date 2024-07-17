#include <iostream>

using namespace std;

int main()
{
    string ords = "label";
    int length = ords.length();
    char decode_string;

    for(int i = 0; i < length; i++){
        decode_string = ords[i] ^ 13;
        cout << decode_string;
    }
    return 0;
}