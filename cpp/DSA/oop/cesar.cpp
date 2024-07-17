// A C++ program to illustrate Caesar Cipher Technique
#include <iostream>
using namespace std;

// This function receives text and shift and
// returns the encrypted text
string encrypt(string text, int s)
{
    string result = "";

    // traverse text
    for (int i = 0; i < text.length(); i++) {
        // Encrypt Uppercase letters
        if (isupper(text[i])) {
            result += char(int(text[i] + s - 65) % 26 + 65);
        }
        // Encrypt Lowercase letters
        else if (islower(text[i])) {
            result += char(int(text[i] + s - 97) % 26 + 97);
        }
        // Handle spaces (keep them unchanged)
        else if (text[i] == ' ') {
            result += text[i];
        }
    }

    // Return the resulting string
    return result;
}

// Driver program to test the above function
int main()
{
    string text = "ABWDM EIZU EIABM XWWT";
    
    for (int s = 1; s <= 50; s++) {
        cout << "Text : " << text;
        cout << "\nShift: " << s;
        cout << "\nCipher: " << encrypt(text, s) << endl << endl;
    }

    return 0;
}
