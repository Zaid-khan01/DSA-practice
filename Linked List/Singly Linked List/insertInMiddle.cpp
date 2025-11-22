// creating a linked list, and inserting a node in middle of a linked list

#include<iostream>
using namespace std;

// class for creating nodes
class Node{
    public:
    int data;
    Node* next;

    Node(int val){  // parametrized constructor
        data = val;
        next = NULL;
    }
};

// class for connecting those nodes, and making a linked list
class List{
    Node* head;
    Node* tail;

public:
    List(){ // non parametrized constructor
        head = tail = NULL; // for empty linked list
    }

    void push_back(int val){   // function for creating a node, and pushing in back
        Node* newNode = new Node(val);
        if(head == NULL){   // if linked list is empty
            head = tail = newNode;  // head & tail pointing to new node
        }

        else{           
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void push_front(int val){   // function for creating a node, and pushing in front
        Node* newNode = new Node(val);
        if(head == NULL){   // if linked list is empty
            head = tail = newNode;  // head & tail pointing to new node
        }

        else{   // if linked list contain atleast one node
            newNode -> next = head; // insert that node in front
            head = newNode; // head points to that node
        }
    }

    void insert(int val, int pos){
        Node* temp = head;
        if(pos<0){
            cout<<"Invalid position!";
            return;
        }
        if(pos == 0){
            // push in front
            push_front(val);
        }
        for(int i=0;i<pos-1; i++){
            if(temp == NULL){
                cout<<"Invalid position\n";
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode -> next = temp->next;
        temp->next = newNode;
    }
    void printLL(){
        Node* temp = head;  // temp pointer pointing to node, where head is pointing
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;  // moving temp pointer forward in list
        }
        cout<<endl;
    }

};
int main(int argc, char const *argv[])
{
    List LL;
    LL.push_back(1);
    LL.push_back(2);
    LL.push_back(3);

    // now we have to print the linked list
    LL.printLL();

    // pushing new node in middle of linked list at any position
    LL.insert(10, 1);

    cout<<"Updated Linked List = "<<endl;
    LL.printLL();
    return 0;
}
