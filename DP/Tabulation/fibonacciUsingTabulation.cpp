#include<bits/stdc++.h>
using namespace std;

// TC = O(n), SC = O(n) because only dp array takes space, there is no recursion tree
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter a number = ";
    cin>>n;

    // instead of recursion, we store the base case first in our dp array
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    // then run a for loop for finding a fib of 'n'
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2]; // same operation performed using dp array
    }

    cout<<"Fibonacci number of "<< n<< " is "<< dp[n];
    return 0;
}
