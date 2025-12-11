#include<iostream>
#include<queue>
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

// function for level order traversal
void levelOrder(Node* root){
    queue<Node* > q;
    q.push(root);

    while(q.size()>0){
        Node* curr = q.front();
        q.pop();

        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> pre = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(pre);
    levelOrder(root);
    return 0;
}
