// creating a linked list, and popping nodes from back of the linked list

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
    // function for removing element from front
    void pop_back(){
        Node* temp = head;
        if(head==NULL){
            cout<<"Linked List is empty, first insert a node";
            return;
        }
        while(temp->next->next!=NULL){  // or we can say, temp->next!=tail both are correct
            temp = temp->next;  
        }

        // now first we have to remove that connection from last node
        temp -> next = NULL;
        delete tail; // delete the tail
        tail = temp;    // now update that tail pointing to last node that is temp
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

    // popping elements from back
    LL.pop_back();

    // now printing new linked list after elements get popped from the back
    LL.printLL();
    return 0;
}
