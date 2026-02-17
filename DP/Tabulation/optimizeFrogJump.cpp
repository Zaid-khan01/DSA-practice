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
    
    int prev = 0;
    int prev2 = 0;
    for(int i=1; i<n; i++){
        int fs = prev + abs(heights[i] - heights[i-1]);

        int ss = INT32_MAX;
        if(i>1) ss = prev2 + abs(heights[i] - heights[i-2]);

        int curri = min(fs, ss);
        prev2 = prev;
        prev = curri;
    }

    cout<<"Minimum energy required to reach the end = " <<prev;
    return 0;
}
