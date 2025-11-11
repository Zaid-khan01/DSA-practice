#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int arr[10], n;
    cout<<"Enter the size of array = ";
    cin>>n;
    cout<<"Enter the elements of array = ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxSum=INT16_MIN;
    for(int st=0;st<n;st++){
        int curSum=0;
        for(int end=st;end<n;end++){
            curSum+=arr[end];
            maxSum = max(curSum, maxSum);
        }
    }
    cout<<"Max sum = "<<maxSum;
    return 0;
}
