#include <iostream>
using namespace std;
class Sum
{
public:
    int sum(int arr[], int size)
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum = sum + arr[i];
        }
        return sum;
    }
};
int main()
{
    int n, a[10];
    cout << "Enter the size of array = ";
    cin >> n;
    cout << "Enter the elements of array = ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Sum s1;
    cout << "Sum of array is = " << s1.sum(a, n);
}