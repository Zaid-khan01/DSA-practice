#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[5], i;
    cout << "Enter elements of array - ";
    for (i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    int minIndex = 0, maxIndex=0;
    for (i = 0; i < 5; i++)
    {
        if (arr[minIndex] > arr[i])
        {
            minIndex = i;
        }
        if (arr[maxIndex] < arr[i])
        {
            maxIndex = i;
        }
    }
    swap(arr[minIndex], arr[maxIndex]);
    cout << "Array after swapping = " << endl;
    for (i = 0; i < 5; i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}
