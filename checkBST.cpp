
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
    if(root==NULL) return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
    return ;
}

bool isBST(Node* root) {
    if(root==NULL) return true;
    // Your code here
    vector<int>ans;
    
    inorder(root,ans);
    
    for(int i = 1;i < ans.size();i++){
        if(ans[i-1] > ans[i]) return false;
    }
    return true;    
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    if (isBST(root)) {
        cout << "The tree is a BST." << endl;
    } else {
        cout << "The tree is not a BST." << endl;
    }

    return 0;
}



