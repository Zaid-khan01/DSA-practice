#include<iostream>
using namespace std;
void reverse(int a[], int size, int start, int end){
    while(start<end){
        swap(a[start], a[end]);
        start++;
        end--;
    }
    cout<<"Array after reversal = ";
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
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
    int begin = 0;
    int end = n-1;
    reverse(a,n, begin, end);
    return 0;
}
