#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>v, int n, int m, int maxAllowedTime){
    int painters = 1, time = 0;
    for(int i=0;i<n;i++){
        if(v[i]>maxAllowedTime) return false;
        if(time + v[i]<=maxAllowedTime){
            time += v[i];
        }
        else{
            painters++;
            time = v[i];
        }
    }
    return painters>m ? false: true;
}
int main(int argc, char const *argv[])
{
    vector<int>v = {10, 20, 30, 40};
    int min = 0, m=2;
    if(m>v.size()) return -1;
    for(int i=0;i<v.size();i++){
        min = max(min, v[i]);
    }
    int sum =0;
    for(int i=0;i<v.size();i++){
        sum += v[i];
    }
    int st = min, end = sum, mid, ans = -1;
    while(st<=end){
        mid = st + (end - st)/2;
        if(isValid(v, v.size(), m, mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            st = mid+1;
        }
    }
    cout<<ans;
    return 0;
}
