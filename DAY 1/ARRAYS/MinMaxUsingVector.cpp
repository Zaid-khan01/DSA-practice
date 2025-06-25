// User function Template for C++
#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
        int min = INT32_MAX;
        int max = INT32_MIN;
        for(int i=0;i<arr.size();i++){
            if(min>arr[i]){
                min = arr[i];
            }
            if(max<arr[i]){
                max = arr[i];
            }
        }
        return {min, max};
    }
};
int main(){
    int size;
    cout<<"Enter the size of array = ";
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter elements of array = ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Solution s1;
    pair<int, int>result = s1.getMinMax(arr);
    cout<<"Minimum element in array is = "<<result.first<<endl;
    cout<<"Maximum element in array is = "<<result.second<<endl;
    return 0;
}