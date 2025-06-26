#include<iostream>
using namespace std;
bool search(int arr[], int size, int key){
    for(int i=0;i<size;i++){
        if(key==arr[i])
            return 1;
    }
    return 0;
}
int main(){
    int n, a[10];
    cout<<"Enter the size of array = ";
    cin>>n;
    cout<<"Enter the elements of array = ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int element;
    cout<<"Enter the element you want to search = ";
    cin>>element;
    int found = search(a, n, element);
    if(found){
        cout<<"Element found!";
    }
    else{
        cout<<"Element Not found!";
    }
    return 0;
}