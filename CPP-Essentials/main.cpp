#include <iostream>

using namespace std;

void swap(int a, int b)
{
    return;
}

int main(void)
{

    int arrSize = 15;
    int arr[15] = {42, 7, 89, 23, 1, 56, 94, 12, 67, 3, 45, 78, 9, 31, 50};
    int temp;

    for (int i = 0; i < arrSize; i++)
    {
        // compare every element to its neighbor
        for (int j = 0; j < arrSize - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "[ ";

    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }

    cout << " ]" << endl;

    return 0;
}