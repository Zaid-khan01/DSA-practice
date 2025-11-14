#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr, int st, int mid, int end){
    vector<int>temp; 
    int i=st, j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]); // comparing element of both halves and then push in temporary array
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    // may be there is some element left of any half, either left half or right half, so we directly push that also
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    // now move the final sorted array from temporary to original array
    for(int idx = 0; idx<temp.size(); idx++){
        arr[st + idx] = temp[idx];  // move element in correct place in original array, so we insert in (idx+st)    
    }
}
void divide(vector<int>&arr, int st, int end){
    if(st<end){
        int mid = st + (end - st)/2;
        divide(arr, st, mid); // left half
        divide(arr, mid+1, end); // right half

        merge(arr, st, mid, end);   // merging both halves
    }
}
int main(int argc, char const *argv[])
{
    vector<int>arr = {12, 31, 35, 8, 32, 17};
    divide(arr, 0, arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
