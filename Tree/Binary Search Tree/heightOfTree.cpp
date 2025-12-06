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

// function for finding of height a tree
int heightOfTree(Node* root){
    if(root == NULL) return 0; // backtrack

    int leftHt = heightOfTree(root->left);
    int rightHt = heightOfTree(root->right);

    return max(leftHt, rightHt)+1;
}

int main(int argc, char const *argv[])
{
    vector<int> pre = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(pre);
    cout<<"Height of a tree is = "<<heightOfTree(root);
    return 0;
}
