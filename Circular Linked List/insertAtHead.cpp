// creating a circular linked list, and then inserting a node at head position
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
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head; // we can also do this without head pointer, via - newNode->next = tail->next
            head = newNode;       // tail->next = newNode
            tail->next = head;
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
    cl.insertAtHead(10);
    cl.insertAtHead(20);
    cl.insertAtHead(30);

    cl.print();
    return 0;
}
