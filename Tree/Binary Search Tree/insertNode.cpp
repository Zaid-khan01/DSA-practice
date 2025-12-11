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

// function for inserting node in a BST
Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val<root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }

    return root;
}

// function for building BST
static int idx = -1; // pointer that traverses whole array
Node* buildBST(vector<int> arr){
    Node* root = NULL;
    for(int val: arr){
        root = insert(root, val);
    }

    return root;
}

// function for inorder traversal
void inOrder(Node* root){
    if(root == NULL) return; // backtrack

    inOrder(root->left); // traverse left subtree
    cout<<root->data<<" "; // traverse parent node
    inOrder(root->right); // traverse right subtree
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = buildBST(arr);
    inOrder(root);
    return 0;
}
