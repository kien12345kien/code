#include <iostream>
#include <cstring>

using namespace std;

#define NUL0  0
#define NUL1  1

class C{
    protected:
        char dataMember1[20];
        int dataMember2;
        double dataMember3;

    public:
        C(string s = "", int i = 0, double d = 1){
            strcpy(dataMember1, s.c_str());
            dataMember2 = i;
            dataMember3 = d;
        }
        void memberFunction1(){
            cout << dataMember1 << ' ' << dataMember2 << ' ' << dataMember3 << endl;
        }
        void memberFunction2(int i, string s = "unknown"){
            dataMember2 = i;
            cout << i << "receive from" << s << endl;
        }
};

C object1("object1", 100,2000), object2("object2"), object3;

int main()
{
    object1.memberFunction1();
    // object3.memberFunction2(0);
    object2.memberFunction1();
    object3.memberFunction1();
}