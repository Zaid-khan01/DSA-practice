#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int>v, int n, int target){
    vector<int>ans;
    int start=0, end=n-1, sum=0;
    while(start<end){
        sum = v[start] + v[end];
        if(sum>target){
            end--;
        }
        else if(sum<target){
            start++;
        }
        else{
           ans.push_back(start);
           ans.push_back(end);
           break;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n, target;
    cout<<"Enter size = ";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter elements of array = ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"Enter target element = ";
    cin>>target;
    vector<int>result = pairSum(v, n, target);
    cout<<result[0]<<", "<<result[1];
    return 0;
}
