#include <iostream>
using namespace std;

int main()
{
    int arr[5], i, j;
    cout << "Enter elements of array - ";
    for (i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    cout << "Unique elements in the array: ";
    for (i = 0; i < 5; i++)
    {
        bool isUnique = true;
        for (j = 0; j < 5; j++)
        {
            if (i != j && arr[i] == arr[j]) // If duplicate found
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}
