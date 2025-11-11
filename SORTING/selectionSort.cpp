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
        int smallestIndex = i;
        for(int j=i+1;j<v.size();j++){
            if(v[j]<v[smallestIndex]){
                smallestIndex = j;
            }
        }
        swap(v[smallestIndex], v[i]);
    }
    cout<<"\nArray after sorting = ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
