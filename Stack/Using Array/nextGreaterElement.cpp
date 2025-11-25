#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> elem = {6, 8, 0, 1, 3};
    vector<int> ans(elem.size());
    stack<int>s;

    for(int i = elem.size()-1;i>=0;i--){
        while(s.size()>0 && elem[i]>=s.top()){
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }
        s.push(elem[i]);
    }

    for(int val: ans){
        cout<<val<<" ";
    }
    return 0;
}
