#include<iostream>
using namespace std;
int findUnique(int *arr, int size)
{
    int ans = 0;
   for(int i=0;i<size;i++){
       ans ^= arr[i];
   }
   return ans;
}
int main(int argc, char const *argv[])
{
    int n, a[10];
    cout<<"Enter the size of array = ";
    cin>>n;
    cout<<"Enter the elements of array = ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Unique element are = ";
    cout<<findUnique(a, n)<<endl;
    return 0;
}
