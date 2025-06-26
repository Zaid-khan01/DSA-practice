#include<iostream>
#include <vector>
using namespace std;

void leftRotate(vector<int>& arr){
    if(arr.size()==0){
        cout<<"Array is empty";
    }
    int n = arr.size();
    int temp = arr[0], i;
    for(i=0;i<n;i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
    cout<<"After rotation = ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
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
    leftRotate(arr);
    return 0;
}
