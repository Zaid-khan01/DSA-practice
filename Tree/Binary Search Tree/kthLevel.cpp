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
void kthLevel(Node* root, int k){
    if(root == NULL) return; // backtrack

    if(k==1){
        cout<<root->data<<" "; // print data when k reaches to level whose value = 1
        return;
    }

    kthLevel(root->left, k-1); // traversing left child
    kthLevel(root->right, k-1); // traversing right child
}

int main(int argc, char const *argv[])
{
    vector<int> pre = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(pre);
    int k;
    cout<<"Enter kth level = ";
    cin>>k;
    kthLevel(root, k);
    return 0;
}
