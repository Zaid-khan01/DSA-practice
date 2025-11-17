// creating a linked list, and pushing nodes in front of a linked list

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

    void printLL(){
        Node* temp = head;  // temp pointer pointing to node, where head is pointing
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;  // moving temp pointer forward in list
        }
    }

};
int main(int argc, char const *argv[])
{
    List LL;
    LL.push_front(1);
    LL.push_front(2);
    LL.push_front(3);

    // now we have to print the linked list
    LL.printLL();
    return 0;
}
