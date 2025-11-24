// In this program i'm implementing stack using linked list, and perform all operations:
// 1. push
// 2. pop
// 3. peek

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};
class Stack{
    Node* head;
    Node* tail;

public:

    Stack(){
        head = tail = NULL;
    }
    // function for pushing element on top of the stack
    void push(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            // inserting node at the beginning, means at the top
            newNode->next = head;
            head = newNode;
        }
    }
    
    // function for popping top of element from stack
    void pop(){
        if(head == NULL){ // 0 node
            cout<<"Stack is empty, first try to push elements in stack!";
            return;
        }
        else{ // more than 1 node
            Node*temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    // function for returning top element from stack
    Node* peek(){
        return head;
    }

    // check that stack is empty or not
    bool isEmpty(){
        return head == NULL;
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
        cout<<s.peek()->data << " ";
        s.pop();
    }
    return 0;
}
