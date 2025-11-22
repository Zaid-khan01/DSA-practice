// create a doubly linked list, and pop node from the back
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
    // function for popping nodes from the back
    void pop_back(){
        if(head == NULL){
            cout<<"Doubly linked list is empty, first try to insert a node";
            return;
        }
        else{
            Node* temp = head;
            while(temp->next!=tail){
                temp = temp->next;
            }
            temp -> next = NULL;
            tail->prev = NULL;
            delete tail;
            tail = temp;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);

        // if our linked list is empty
        if(head == NULL){
            head = tail = newNode; // head & tail now both pointing to same node, bcz there is only one node
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            newNode ->next = NULL;
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
    DL.push_back(10);
    DL.push_back(20);
    DL.push_back(30);

    // list befor popping node from back
    DL.print();

    DL.pop_back();
    // List after node is popped
    DL.print();
    return 0;
}
