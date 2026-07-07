// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

void insert(vector<int> &v, int temp){
    if(v.empty() || v.back() <= temp){
        v.push_back(temp);
        return;
    }
    
    int elem = v.back();
    v.pop_back();
    insert(v, temp);
    v.push_back(elem);
}
void sort(vector<int> &v){
    if(v.size() <= 1) return;
    
    int temp = v.back();
    v.pop_back();
    sort(v);
    
    insert(v, temp);
}
int main() {
    int n;
    cout<<"Enter size = ";
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int elem;
        cin>>elem;
        v.push_back(elem);
    }
    
    sort(v);
    
    cout<<"Array after sorted = "<<endl;
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}