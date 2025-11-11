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
    int p = 1;
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        p = p*v[i];
    }
    for(int i=0;i<n;i++){
        ans[i] = p/v[i];
        v.push_back(ans[i]);
    }
    cout<<"Final array = ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
