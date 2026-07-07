// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
using namespace std;

void insert(stack<int> &st, int temp){
    if(st.empty() || st.top() <= temp){
        st.push(temp);
        return;
    }
    
    int elem = st.top();
    st.pop();
    insert(st, temp);
    st.push(elem);
}
void sort(stack<int> &st){
    if(st.empty()) return;
    
    int temp = st.top();
    st.pop();
    sort(st);
    
    insert(st, temp);
}
int main() {
    int n;
    cout<<"Enter size = ";
    cin>>n;
    stack<int> st;
    for(int i=0; i<n; i++){
        int elem;
        cin>>elem;
        st.push(elem);
    }
    
    sort(st);
    
    cout<<"Stack after sorted = "<<endl;
    for(int i=0; i<n; i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}