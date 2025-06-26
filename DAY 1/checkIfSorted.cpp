#include<iostream>
#include <vector>
using namespace std;

bool check(vector<int>& arr){
    int n = arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i] > arr[(i+1)%n]){
            count++;
        }
    }
    return count <= 1;
}
int main(int argc, char const *argv[])
{
    int i, n;
    cout<<"Enter the size of array = ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array = ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    if(check(arr)){
        cout<<"Array is sorted";
    }
    else
        cout<<"Array is not sorted";
    return 0;
}
