#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* rightMostInLeftSubtree(Node* root){
    Node* ans;
    while(root != NULL){
        ans = root;
        root = root->right;
    }
    return ans;
}

Node* leftMostInRightSubtree(Node* root){
    Node* ans;
    while(root != NULL){
        ans = root;
        root = root->left;
    }
    return ans;
}

// function for inorder predecessor and successor
vector<int> getPredAndSucc(Node* root, int key){
    Node* pred = NULL;
    Node* succ = NULL;
    Node* curr = root;
    while(curr != NULL){
        if(key < curr->data){
            succ = curr;
            curr = curr->left;
        }
        else if(key > curr->data){
            pred = curr;
            curr = curr->right;
        }
        else{
            if(curr->left != NULL){
                pred = rightMostInLeftSubtree(curr->left);
            }
            
            if(curr->right != NULL){
                succ = leftMostInRightSubtree(curr->right);
            }
            break;
        }
    }
    return {pred->data, succ->data};
}

int main(int argc, char const *argv[])
{
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    int key;
    cout<<"Enter the key for which you want inorder predecessor and successor = ";
    cin>>key;
    vector<int> ans = getPredAndSucc(root, key);
    cout<<"Inorder predecessor for key "<<key<<" is: "<<ans[0]<<endl;
    cout<<"Inorder successor for key "<<key<<" is: "<<ans[1];
    return 0;
}
