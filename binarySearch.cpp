#include <iostream>
using namespace std;
int binarySearch(int arr[], int start, int end, int target)
{
    while (start <= end)
    {
        // int mid = (start + end) / 2; // if my start will INT_MAX and end will INT_MAX then addition of both will overflow of int
        // optimize formula for mid calculation
        int mid = start + (end-start)/2;

        if (target < arr[mid])
        {
            end = mid - 1;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else if (target == arr[mid])
        {
            return mid;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int arr[10], n, ans;
    cout << "Enter size = ";
    cin >> n;
    cout << "Enter elements = ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter target value = ";
    cin >> target;
    ans = binarySearch(arr, 0, n - 1, target);
    if(ans>0){
        cout << "Element found at " << ans << " index";
    }
    else{
        cout<<"Element Not Found";
    }
    return 0;
}
