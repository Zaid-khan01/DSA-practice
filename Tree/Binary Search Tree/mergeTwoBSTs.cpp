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
Node* buildBST(vector<int>&arr){
    Node* root = NULL;
    for(int val: arr){
        root = insert(root, val);
    }

    return root;
}

// function for inorder traversal
void inOrder(Node* root, vector<int> &arr){
    if(root == NULL) return; // backtrack

    inOrder(root->left, arr); // traverse left subtree
    arr.push_back(root->data);
    inOrder(root->right, arr); // traverse right subtree
}

// function for creating merged BST from 2 BST's
Node* buildBSTfromSortedArr(vector<int>arr, int st, int end){
    if(st>end) return NULL;
    int mid = st + (end - st)/2;
    Node* root = new Node(arr[mid]);
    root->left = buildBSTfromSortedArr(arr, st, mid-1);
    root->right = buildBSTfromSortedArr(arr, mid+1, end);

    return root;
}

// merging two BST, and giving the combined inorder array
Node* merge2BST(Node* root1, Node* root2){
    vector<int> arr1, arr2;
    inOrder(root1, arr1);
    inOrder(root2, arr2);

    vector<int> temp;
    int i = 0, j = 0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            temp.push_back(arr1[i++]);
        }
        else{
            temp.push_back(arr2[j++]);
        }
    }
    while(i<arr1.size()){
        temp.push_back(arr1[i++]);
    }
    while(j<arr2.size()){
        temp.push_back(arr2[j++]);
    }

    return buildBSTfromSortedArr(temp, 0, temp.size()-1);
}

int main(int argc, char const *argv[])
{
    vector<int> arr1 = {8, 2, 1, 10};
    vector<int> arr2 = {5, 3, 0};

    Node* root1 = buildBST(arr1);
    Node* root2 = buildBST(arr2);

    // combining both BST
    Node* root = merge2BST(root1, root2);
    vector<int> seq;
    inOrder(root, seq);
    cout<<"Inorder sequence of combined BST = ";
    for(int i: seq){
        cout<<i<<" ";
    }
    return 0;
}
