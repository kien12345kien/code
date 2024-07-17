#include <iostream>
#include <string>
#include <cstring>  // Added for strcpy

using namespace std;

class C {
public:
    // Fixed the constructor syntax
    C(const std::string& s = " ", int i = 0, double d = 1) {
        dataMember1 = s;
        dataMember2 = i;
        dataMember3 = d;
    }

    void memberFunction1() {
        cout << dataMember1 << ' ' << dataMember2 << ' ' << dataMember3 << endl;
    }

protected:
    std::string dataMember1;
    int dataMember2;
    double dataMember3;
};

int main() {
    // Create an instance of class C
    C obj("Hello", 42, 3.14);

    // Call member function
    obj.memberFunction1();

    return 0;
}
