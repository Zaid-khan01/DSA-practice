#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

// function for priting the nodes that are visible from top view
void topView(Node* root){
    queue<pair<Node*, int>>q;
    map<int, int>m;
    q.push({root, 0}); // pushing first node in a queue

    while(q.size()>0){
        Node* curr = q.front().first; // storing the first node->data in a level
        int currHD = q.front().second; // storing the corresponding horizontal distance of node in a tree
        q.pop();

        if(m.find(currHD) == m.end()){
            m[currHD] = curr->data;
        }

        // traverse left node
        if(curr->left!=NULL){
            q.push({curr->left, currHD-1});
        }
        
        // traverse right node
        if(curr->right!=NULL){
            q.push({curr->right, currHD+1});
        }
    }

    for(auto it: m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    vector<int> pre = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(pre);
    topView(root);
    return 0;
}
