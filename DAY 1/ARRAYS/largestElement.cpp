#include <iostream>
#include <vector>
using namespace std;

int maxElement(const vector<int> &arr)
{
    if (arr.empty())
    {
        cout << "Array is empty";
    }

    int max = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int main(int argc, char const *argv[])
{
    int n, i;
    cout << "Enter the size of array = ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter elements = ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int largest = maxElement(arr);
    cout << "Largest element in array is = " << largest;
    return 0;
}
