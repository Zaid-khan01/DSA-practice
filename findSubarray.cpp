#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[5];
    cout<<"Enter the elements of array = ";
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    cout<<"Subarrays are = "<<endl;
    for(int st = 0;st<5;st++){
        for(int end=st; end<5;end++ ){
            for(int i=st;i<=end;i++){
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
