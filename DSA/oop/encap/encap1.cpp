#include <iostream>
#include <cstring>

using namespace std;

class C{
    private:
        string dataMember1;
        int dataMember2;
        double dataMember3;

    public:
        C(string s, int i, double d){
            this->dataMember1 = s;
            this->dataMember2 = i;
            this->dataMember3 = d;
        }
        // void memberFunction1(){
        //     cout << dataMember1 << ' ' << dataMember2 << ' ' << dataMember3 << endl;
        // }
        // void memberFunction2(int i, string s = "unknown"){
        //     dataMember2 = i;
        //     cout << i << "receive from "<< s << endl;
        // }
        void get1(string s){
            this->dataMember1 = s;
        }
        void get2(int i){
            this->dataMember2 = i;
        }
        void get3(double d){
            this->dataMember3 = d;
        }
        string set1(){
            return dataMember1;
        }
        int set2(){
            return dataMember2;
        }
        double set3(){
            return dataMember3;
        }
        void returnVal(){
            cout << dataMember1 << ' ' << dataMember2 << ' ' << dataMember3 << endl;
        }
        
};

C object1("object1", 100,2000), object2("fknv", 74938,423908);

int main(){
    object1.returnVal();
    object2.returnVal();
}