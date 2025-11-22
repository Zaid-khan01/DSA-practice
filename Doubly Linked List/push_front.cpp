// create a doubly linked list, and pushed node in front 
#include<iostream>
using namespace std;
// class for initializing nodes with data & their respective pointers
class Node{
public:
    Node*next;
    Node* prev;
    int data;
    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

// class for making connections b/w those nodes
class DoublyList{
    Node* head;
    Node* tail;

public:
    DoublyList(){
        head = tail = NULL;
    }
    // insert in front function
    void push_front(int val){
        Node* newNode = new Node(val);

        // if our linked list is empty
        if(head == NULL){
            head = tail = newNode; // head & tail now both pointing to same node, bcz there is only one node
        }
        else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }

    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" <=> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(int argc, char const *argv[])
{
    DoublyList DL;
    DL.push_front(10);
    DL.push_front(20);
    DL.push_front(30);

    DL.print();
    return 0;
}
