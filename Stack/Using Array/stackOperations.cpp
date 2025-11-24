// In this program i'm implementing stack using vector - dynamic array, and perform all operations:
// 1. push
// 2. pop
// 3. peek

#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int>v;

public:
    // function for pushing element on top of the stack
    void push(int val){
        v.push_back(val);
    }
    
    // function for popping top of element from stack
    void pop(){
        if(v.size()<=0){
            cout<<"\nStack is empty";
            return;
        }
        v.pop_back();
    }

    // function for returning top element from stack
    int peek(){
        if(v.size()<=0){
            cout<<"\nStack is empty";
            return 1;
        }
        return v[v.size()-1];
    }

    // check that stack is empty or not
    bool isEmpty(){
        return v.size() == 0;
    }
};
int main(int argc, char const *argv[])
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<"Elements in stack are = ";
    while(!s.isEmpty()){
        cout<<s.peek() << " ";
        s.pop();
    }
    return 0;
}
