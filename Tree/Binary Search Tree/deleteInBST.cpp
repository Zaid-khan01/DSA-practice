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

// function for search an element in BST
bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key) return true;

    if(root->data > key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

Node* getInorderSuccessor(Node* root){
    while(root!=NULL && root->left!=NULL){
        root = root->left;
    }
    return root;
}
Node* delNode(Node* root, int key){
    if(root == NULL)
        return NULL;
    
    if(key < root->data){
        root->left = delNode(root->left, key);
    }
    else if(key > root->data){
        root->right = delNode(root->right, key);
    }
    else{
        // key == root
        if(root->left == NULL){
            Node* temp = root->right;
            delete root->left;
            return temp;
        }
        else if(root->right == NULL){
            Node*temp = root->left;
            delete root->right;
            return temp;
        }
        else{
            Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = delNode(root->right, IS->data);
        }
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
    int elem;

    cout<<"Before deletion = ";
    Node* root = buildBST(arr);
    inOrder(root);
    cout<<endl;
    
    delNode(root, 5);
    
    cout<<"After deletion = ";
    inOrder(root);
    cout<<endl;
    return 0;
}
