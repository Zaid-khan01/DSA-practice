#include<iostream>
#include<vector>
#include<stack>
using namespace std;

stack<int>s;
int getCelebrity(vector<vector<int>>arr){
    int n = arr.size();
    for(int i = 0; i<n-1; i++){
        s.push(i);
    }
    while(s.size()>1){ // atleast 2 persons in stack
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();

        if(arr[i][j] == 0){
            s.push(i); // pushing normal person
        }
        else{
            s.push(j);  // pushing celebrity
        }
    }
    int celeb = s.top();   // at the end there is only one person left in stack, that can be celebrity
    int j;
    for(int i = 0; i<n;i++){
        if((i!=celeb) && (arr[i][celeb] == 0) || arr[celeb][i] == 1){
            return -1; 
        }
    }
    return celeb;

}
int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    
    int ans = getCelebrity(arr);
    cout<<"Celebrity is = "<<ans;

    return 0;
}
