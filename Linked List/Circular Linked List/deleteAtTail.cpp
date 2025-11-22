// creating a circular linked list, and then deleting a node from tail position
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
    // function for deleting last node of Circular linked list
    void deleteAtTail(){
        if(head == NULL){ // no node
            cout<<"Linked list is empty, first try to insert nodes\n";
            return;
        }
        else if(head==tail){ // 1 node
            delete head;
            head = tail = NULL;
        }
        else{ // mroe than 1 node
            Node* temp = head;
            while(temp->next!=tail){
                temp = temp->next;
            }
            temp -> next = tail->next;
            tail->next = NULL;
            delete tail;
            tail = temp;
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

    // Linked list before deleting last node
    cl.print();

    // Linked list after deleting last node
    cl.deleteAtTail();
    cout<<"Updated linked list = \n";
    cl.print();
    return 0;
}
