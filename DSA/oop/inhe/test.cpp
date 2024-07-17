#include <iostream>

using namespace std;

class Animal{
    private:
        string name;

    public:
        void makeNoise(){
            cout << "Hmm" << endl;
        }
};

class Cow : public virtual Animal{
    private:
        bool givesMilk;
    
    public:
        void makeNoise(){
            cout << "Moo" << endl;
        }
};

class Dog : public virtual Animal{
    public:
    void chaseCats(){
        cout << "Im comming cat." << endl;
    }
};

int main() {
    Cow cow;
    Dog dog;

    cow.makeNoise(); // Outputs: Moo
    dog.makeNoise(); // Outputs: Woof
    dog.chaseCats(); // Outputs: I'm coming, cat.

    return 0;
}