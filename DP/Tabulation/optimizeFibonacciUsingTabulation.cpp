#include<bits/stdc++.h>
using namespace std;

// TC = O(n), SC = O(1) bcz we are not using anything that takes space in 'n'
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter a number = ";
    cin>>n;

    // instead of dp array, we store the values in every iteration of loop
    // we declare prev2, prev and curri, and every time we update prev2 and prev, so that they increment by 1

    // for base case we store them in variable
    int prev2 = 0;
    int prev = 1;
    for(int i=2; i<=n; i++){
        int curri = prev + prev2;
        prev2 = prev; // updating every iteration
        prev = curri;
    }

    // at the end, we are going to n+1, so we print 'prev' not 'curri'
    cout<<"Fibonacci number of "<< n<< " is "<< prev;
    return 0;
}
