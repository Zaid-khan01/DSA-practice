#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    // ------------------- BRUTE FORCE ---------------------
    // int arr[] = {1, 2, 3, 3, 1, 3, 3};
    // int count;
    // for(int i=0;i<7;i++){
    //     count=1;
    //     for(int j=i+1;j<7;j++){
    //         if(arr[i]==arr[j]){
    //             count++;
    //         }
    //         if(count>(7/2)){
    //             cout<<arr[i];
    //             break;
    //         }
    //     }
    // }


    // ------------------- OPTIMIZE APPROACH ----------------------
    int n, mid;
    cout<<"Enter size = ";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter elements of array = ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    mid = n/2;
    sort(v.begin(), v.end());
    cout<<v[mid];
    return 0;
}
