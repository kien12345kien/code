#include <iostream>
#include <string>
using namespace std;

class Person{
    string name;
    int age;

public:
    Person(string name, int age){
        this->age = age;
        this->name = name;
    }
    void setName(string name){
        this->name = name;
    }
    void setAge(int age){
        this->age = age;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
};

int main()
{
    Person person1("John Doe", 30);
    cout << person1.getAge() << endl;
    cout << person1.getName() << endl;
}