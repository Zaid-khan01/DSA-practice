#include<iostream>
#include<vector>
using namespace std;

int removesDuplicates(vector<int>& arr){
    if(arr.size()==0) return 0;

    int i=0;
    for(int j=1;j<arr.size();j++){
        if(arr[j]!=arr[i]){
            i++;
        }
        arr[i]=arr[j];
    }
    return i+1;
}
int main(int argc, char const *argv[])
{
    int n, i;
    cout<<"Enter size of array = ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array = ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int total = removesDuplicates(arr);
    cout<<"After removing duplicates from array total elements are = "<<total<<endl;

    cout<<"Elements after removing duplicates : ";
    for(i=0;i<total;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
