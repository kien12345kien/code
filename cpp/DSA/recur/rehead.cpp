#include <iostream>

void fun(int n)
{
    if (n > 0)
    {
        fun(n-1);
        std::cout << " " << n;
    }
}

int main()
{
    int x = 3;
    fun(x);
    return 0;
}