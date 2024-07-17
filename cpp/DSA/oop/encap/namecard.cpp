#include <iostream>
using namespace std;

class namecard
{
    private:
        string name;
        string email;
        string phone;
    
    public:
        namecard(string name, string email, string phone){
            this->email = email;
            this->name = name;
            this->phone = phone;
        }
        void setName(string name){
            this->name = name;
        }
        void setPhone(string phone){
            this->phone = phone;
        }
        void setEmail(string email){
            this->email = email;
        }
        string getPhone(){
            return phone;
        }
        string getEmail(){
            return email;
        }
        string getName(){
            return name;
        }
};

int main(){
    namecard nc("3132143243", "dsnaucnudn", "4893fj834fj93f");
    cout << nc.getEmail() << endl << nc.getName() << endl << nc.getPhone();
}