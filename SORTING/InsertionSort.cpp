#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int>v = {4, 1, 5, 2, 3};
    cout<<"Array before sorting = ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    int prev;
    for(int i=1;i<v.size();i++){
        int currElement = v[i];
        prev = i-1;
        while(prev>=0 && v[prev] > currElement){
            v[prev+1] = v[prev];
            prev--;
        }
        v[prev+1] = currElement;
    }
    cout<<"\nArray after sorting = ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
