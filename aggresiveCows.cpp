#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(vector<int>v, int n, int c, int maxAllowedDistance){
    int cows = 1, lastLocation = v[0];
    for(int i=1;i<n;i++){
        if(v[i]-lastLocation >= maxAllowedDistance){
            cows++;
            lastLocation = v[i];
        }
        if(cows == c){
            return true;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    vector<int>v = {1, 2, 8, 4, 9};
    sort(v.begin(), v.end());
    int st = 1, end = v[v.size()-1]-v[0], mid, ans = -1, c=3;
    while(st<=end){
        mid = st + (end - st)/2;
        if(isValid(v, v.size(), c, mid)){
            ans = mid;
            st = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout<<ans;
    return 0;
}
