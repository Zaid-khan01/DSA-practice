#include <iostream>
#include <vector>
using namespace std;

int maxElement(const vector<int> &arr)
{
    if (arr.size()<2)
    {
        cout << "Array have not enough elements";
        return -1;
    }

    int largest = INT64_MIN;
    int slargest = INT64_MIN;
    for(int num:arr){
        if(num>largest){
            slargest = largest;
            largest = num;
        }
        else if(num>slargest && num!=largest){
            slargest = num;
        }
        else 
            return -1;
    }
    return slargest;
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
    int slargest = maxElement(arr);
    cout << "Second largest element in array is = " << slargest;
    return 0;
}
