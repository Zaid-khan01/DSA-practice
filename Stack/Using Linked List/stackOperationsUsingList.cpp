// In this program i'm implementing stack using vector - dynamic array, and perform all operations:
// 1. push
// 2. pop
// 3. peek

#include<iostream>
#include<list>

using namespace std;

class Stack{
    list<int>ll;

public:
    // function for pushing element on top of the stack
    void push(int val){
        ll.push_front(val);
    }
    
    // function for popping top of element from stack
    void pop(){
        if(ll.size()<=0){
            cout<<"\nStack is empty";
            return;
        }
        ll.pop_front();
    }

    // function for returning top element from stack
    int peek(){
        return ll.front();
    }

    // check that stack is empty or not
    bool isEmpty(){
        return ll.size() == 0;
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
