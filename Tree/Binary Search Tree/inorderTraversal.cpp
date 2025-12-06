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

// function for building tree
static int idx = -1; // pointer that traverses whole preorder array
Node* buildTree(vector<int> pre){
    idx++;
    if(pre[idx] == -1) return NULL;

    Node* root = new Node(pre[idx]);
    root->left = buildTree(pre); // recursively build left subtree
    root->right = buildTree(pre); // // recursively build right subtree

    return root;
}

// function for inorder traversal
void inOrder(Node* root){
    if(root == NULL) return; // backtrack

    inOrder(root->left); // traverse left subtree first
    cout<<root->data<<" "; // then print root node
    inOrder(root->right); // traverse right subtree last
}

int main(int argc, char const *argv[])
{
    vector<int> pre = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(pre);
    inOrder(root);
    return 0;
}
