#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int partition(vector<int> &arr, int st, int end)
{
    int idx = st - 1;
    int pivot = arr[end];
    for (int j = st; j <= end - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}
void QS(vector<int> &arr, int st, int end)
{
    if ((st < end))
    {
        int pivot = partition(arr, st, end);
        QS(arr, st, pivot - 1);  // left part
        QS(arr, pivot + 1, end); // right part
    }
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {5, 6, 4, 2, 1, 3};
    QS(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
