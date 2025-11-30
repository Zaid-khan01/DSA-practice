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

class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){
        head = tail = NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if(empty()){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if(empty()){ // 0 node
            cout<<"Queue is empty, first try to insert elements";
            return;
        }
        else if(head == tail){ // 1 node
            delete head;
            head = tail = NULL;
        }
        else{ // more than 1 node
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int front(){
        return head->data;
    }

    bool empty(){
        return head==NULL;
    }

    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    q.print();

    // popped first element
    q.pop();

    // Queue after popping first element
    cout<<"Queue after popping first element: ";
    q.print();
    
    return 0;
}
