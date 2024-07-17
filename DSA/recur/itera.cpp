#include <iostream>
using namespace std;

void draw(int n);

int main()
{
    int height = 4;
    draw(height);
}

void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "µ";
        }
        cout << endl;
        
    }
    
}
