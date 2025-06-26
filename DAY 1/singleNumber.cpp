// In this we have to find the number that appears exactly one time in array

#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, i;
    cout<<"Enter the size of array = ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array = ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    return 0;
}

