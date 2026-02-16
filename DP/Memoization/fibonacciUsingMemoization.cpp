#include <bits/stdc++.h>
using namespace std;

// TC = O(n), SC = O(n) + O(n) -> one for recursion & one for dp array 
int fibonacciNum(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    // agar humar dp array me already fib(n) ki value present hai to use recompute nhi karenge, directly return that
    if (dp[n] != -1)
        return dp[n];

    // agar dp array me fib(n) nhi hai, to use compute krke store karayenge for future use
    return dp[n] = fibonacciNum(n - 1, dp) + fibonacciNum(n - 2, dp);
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter a number = ";
    cin >> n;

    vector<int> dp(n + 1, -1); // bcz start 0 se hota hai -> n+1
    int result = fibonacciNum(n, dp);
    cout << "Fibonacci number of " << n << " is " << result;
    return 0;
}
