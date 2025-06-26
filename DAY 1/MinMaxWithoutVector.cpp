#include<iostream>
using namespace std;

void minElement(int arr[], int size){
    int min = INT32_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    cout<<"Minimum element is = "<<min<<endl;
}
void maxElement(int arr[], int size){
    int max = INT32_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    cout<<"Maximum element is = "<<max<<endl;
}
int main(){
    int n, a[10];
    cout<<"Enter the size of array = ";
    cin>>n;
    cout<<"Enter the elements of array = ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    minElement(a, n);   // for finding minimum element
    maxElement(a, n);   // for finding maximum element
}