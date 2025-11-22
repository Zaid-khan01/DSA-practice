// creating a circular linked list, and then deleting a node from head position
#include <iostream>
using namespace std;

// class for creating & initializing nodes
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// class for making connections b/w those nodes
class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList(){
        head = tail = NULL;
    }
    // function for deleting first node of Circular linked list
    void deleteAtHead(){
        if(head == NULL){ // no node
            cout<<"Linked list is empty, first try to insert nodes\n";
            return;
        }
        else if(head==tail){ // 1 node
            delete head;
            head = tail = NULL;
        }
        else{   // more than 1 node
            tail->next = head->next;             
            head->next = NULL;             
            delete head;             
            head = tail->next;
        }
    }
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }
    void print(){
        if(head == NULL){
            cout<<"Linked list is empty first try to insert the nodes\n";
            return;
        }
        cout<<head->data<<"->";
        Node* temp = head->next; // or we can write 'temp = tail->next' also
        while(temp!=head){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<temp->data<<"...same repeats"<<endl;
    }
};
int main(int argc, char const *argv[])
{
    CircularList cl;
    cl.insertAtTail(10);
    cl.insertAtTail(20);
    cl.insertAtTail(30);

    // Linked list before deleting first node
    cl.print();

    // Linked list after deleting first node
    cout<<"Updated linked list = \n";
    cl.deleteAtHead();
    cl.print();
    return 0;
}
