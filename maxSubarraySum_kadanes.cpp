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
    int maxSum=INT16_MIN, curSum=0;
    for(int i=0;i<n;i++){
        curSum += arr[i];
        maxSum = max(curSum, maxSum);
        if(curSum<0){
            curSum=0;
        }
    }
    cout<<"Max Sum = "<<maxSum;
    return 0;
}
