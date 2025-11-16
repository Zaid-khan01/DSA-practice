#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]); // comparing element of both halves and then push in temporary array
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            invCount += mid - i + 1; // if (arr[i]>arr[j]) then from arr[i] to arr[mid] all elements are (>) that arr[j]
        }
    }

    // may be there is some element left of any half, either left half or right half, so we directly push that also
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    // now move the final sorted array from temporary to original array
    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[st + idx] = temp[idx]; // move element in correct place in original array, so we insert in (idx+st)
    }
    return invCount;
}
int divide(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        int leftInvCount = divide(arr, st, mid);       // left half inversion count
        int rightInvCount = divide(arr, mid + 1, end); // right half inversion count

        int invCount = merge(arr, st, mid, end); // merging both halves, and returning inversion count
        return invCount;
    }
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    int invCount = divide(arr, 0, arr.size() - 1);
    cout << invCount;
    return 0;
}
