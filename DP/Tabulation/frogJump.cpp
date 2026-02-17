#include<bits/stdc++.h>
using namespace std;

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
    vector<int> dp(n, 0);
    dp[0] = 0;

    for(int i=1; i<n; i++){
        int fs = dp[i-1] + abs(heights[i] - heights[i-1]);

        int ss = INT32_MAX;
        if(i>1) ss = dp[i-2] + abs(heights[i] - heights[i-2]);

        dp[i] = min(fs, ss);
    }

    cout<<"Minimum energy required to reach the end = " <<dp[n-1];
    return 0;
}
