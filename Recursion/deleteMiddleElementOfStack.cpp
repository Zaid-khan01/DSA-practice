// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
using namespace std;
void deleteMid(stack<int> &st, int n){
    if(st.size() == ((n/2)+1)) {
        st.pop();
        return;
    }
    
    int temp = st.top();
    st.pop();
    deleteMid(st, n);
    st.push(temp);
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
    
    deleteMid(st, n);
    
    cout<<"Stack after deletion of middle element = "<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}