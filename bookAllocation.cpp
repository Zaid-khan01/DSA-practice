#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> v, int n, int m, int maxAllowedPages)
{
    int students = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > maxAllowedPages)
        {
            return false;
        }
        if (pages + v[i] <= maxAllowedPages)
        {
            pages += v[i];
        }
        else
        {
            students++;
            pages = v[i];
        }
    }
    return students > m ? false : true;
}
int main(int argc, char const *argv[])
{
    int n, m=2, ans = -1;
    cout << "Enter size = ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter elements = ";
    if (m > n)
            return -1; // no. of students books se jyada aa jaye to direct -1, it means har students ko book nhi mil payegi
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
    }
    int st = 0, end = sum, mid;
    while (st <= end)
    {
        mid = st+(end-st)/2;
        if (isValid(v, n, m, mid))
        {
            ans = mid;
            end = mid - 1; // min pages find karna hai, isliye left jayenge if allocation is valid
        }
        else
        {
            st = mid + 1; // invalid aa jaye to right move karenge max find krne keliye
        }
    }
    cout << ans;
    return 0;
}
