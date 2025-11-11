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
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size()-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
    cout<<"\nArray after sorting = ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
