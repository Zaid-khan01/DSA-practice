#include<iostream>
#include<vector>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter size = ";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter elements = ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // --------------- BRUTE FORCE ------------
    // int count, maxi = 0, mini, area;
    // for(int i=0;i<n;i++){
    //     count = 0;
    //     for(int j=i+1;j<n;j++){
    //         count++;
    //         mini = min(v[i], v[j]);
    //         area = mini*count;
    //         maxi = max(maxi, area);
    //     }
    // }
    // cout<<maxi;


    // ------------ SOME OMPTIMAL ------------
    int start = 0, end = n-1, mini, maxi=0;
    int area;
    while(start<end){
        mini = min(v[start], v[end]);
        area = mini * (end - start);
        maxi = max(maxi, area);
        (v[start]>v[end]) ? end-- : start++;
    }
    cout<<maxi;
    return 0;
}
