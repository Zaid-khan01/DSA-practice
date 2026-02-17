#include <bits/stdc++.h>
using namespace std;

int frogJump(int ind, vector<int> &heights, vector<int> &dp)
{
    if (ind == 0)
        return 0;

    if (dp[ind] != 0)
        return dp[ind];

    int left = frogJump(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = frogJump(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);

    return dp[ind] = min(left, right);
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter no. of heights = ";
    cin >> n;
    vector<int> heights(n);
    cout << "Enter heights = ";
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    vector<int> dp(n + 1, 0);
    int res = frogJump(n - 1, heights, dp);
    cout << "Minimum energy required to reach the end = " << res;
    return 0;
}
