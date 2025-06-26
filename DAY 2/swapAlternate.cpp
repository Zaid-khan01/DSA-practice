#include <iostream>
using namespace std;

// alternate position wale element ko swap karna hai, matlab a[0] & a[1], a[2] & a[3]

void swapAlternate(int arr[], int size)
{
    int j = 0;
    for (int i = 0; i + 1 < size; i += 2)
    {
        swap(arr[i], arr[i + 1]);
    }
}
void printArray(int arr[], int size)
{
    cout << "Array after alternate position swap - " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main(int argc, char const *argv[])
{
    int n, a[10];
    cout << "Enter the size of array = ";
    cin >> n;
    cout << "Enter the elements of array = ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    swapAlternate(a, n);
    printArray(a, n);
    return 0;
}
