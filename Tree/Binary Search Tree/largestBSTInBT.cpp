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

class Info{
public:
    int max, min, sz;
    Info(int mi, int ma, int size){
        min = mi;
        max = ma;
        sz = size;
    }
};

Info helper(Node* root){
    if(root == NULL){
        return Info(INT32_MAX, INT32_MIN, 0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->data > left.max && root->data < right.min){
        int currMin = min(root->data, left.min);
        int currMax = max(root->data, right.max);
        int currSz = left.sz + right.sz + 1;

        return Info(currMin, currMax, currSz);
    }

    return Info(INT32_MIN, INT32_MAX, max(left.sz, right.sz));
}

int largestBSTInBT(Node* root){
    Info info = helper(root);
    return info.sz; // largest BST size in Binary tree
}

int main(int argc, char const *argv[])
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    cout<<"Largest BST size in this Binary tree is = "<<largestBSTInBT(root);
    return 0;
}
