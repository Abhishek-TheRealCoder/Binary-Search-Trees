// Kth Smallest Element in a BST
#include <bits/stdc++.h>
using namespace std;

class Node {    
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};


void inorder(Node*root,vector<int>&ans){
    if(root==NULL)return ;
    
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
    return ;
}

    // Return the Kth smallest element in the given BST
int kthSmallest(Node *root, int k) {
    // add code here.
    if(root==NULL) return -1;
    
    vector<int>ans;
    inorder(root,ans);
    if(ans.size() < k) return -1;
    
    return ans[k-1];
}


int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    int k = 3; // Example value for k
    cout << "The " << k << "th smallest element is: " << kthSmallest(root, k) << endl;
    return 0;
}