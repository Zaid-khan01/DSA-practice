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

// function for preorder traversal
void preOrder(Node* root){
    if(root == NULL) return; // backtrack

    cout<<root->data<<" ";
    preOrder(root->left); // traverse left subtree
    preOrder(root->right); // traverse right subtree
}

// function for transforming normal tree to sum tree
int sumTree(Node* root){
    if(root == NULL) return 0;

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->data += leftSum + rightSum;

    return root->data;
}

int main(int argc, char const *argv[])
{
    vector<int> pre = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(pre);

    cout<<"Before conversion : ";
    preOrder(root);
    cout<<endl;

    sumTree(root);

    cout<<"After conversion : ";
    preOrder(root);
    cout<<endl;
    return 0;
}
