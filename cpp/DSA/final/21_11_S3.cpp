#include <iostream>

void max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr [i] >= max)
        {
            max = arr[i];
        }
    }
    for(int i = 0; i < size-2; i++)
    {
        for (int j = i + 1; j < size-1; j++)
        {
            for(int k = i + 2; k < size; k++)
            {
                if (arr[i]*arr[j] == arr[k])
                {
                    std::cout << arr[i] << " and " << arr[j] << " and " << arr[k]<< std::endl;
                }
            }
        }
    }
}

int main()
{
    int arra[] = {4, 15, 45, 9, 40, 27, 3, 5, 10};
    int length = sizeof(arra)/sizeof(arra[0]);

    max(arra, length);
}