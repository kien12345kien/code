#include <iostream>

using namespace std;

class Class1{
    public:
        virtual void f(){
            cout << "Function f() in Class1" << endl;
        }

        void g(){
            cout << "Function g() in Class1" << endl;
        }
};

class Class2{
    public: virtual void f(){
        cout << "Function f() in Class2" << endl;
    }

    void g(){
        cout << "Function g() in Class2" << endl;
    }
};

class Class3{
    public:
        virtual void h(){
            cout << "Funcion h() in Class3" << endl;
        }
};

int main(){
    Class1 obj1, *p;
    Class2 obj2;
    Class3 obj3;

    p = &obj1;
    p->f();
    p->g();
    p = (Class1*) &obj2;
    p->f();
    p->g();
    p = (Class1*) &obj3;
    p->f();
    p->g();
    
    return 0;
}