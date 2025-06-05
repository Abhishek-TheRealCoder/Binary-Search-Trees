#include <bits/stdc++.h>
using namespace std;
class Node{
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
int kthLargest(Node *root, int k) {
    // Your code here
    if(root==NULL || k==0) return 0;
    
    vector<int>ans;
    inorder(root,ans);
    
    reverse(ans.begin(),ans.end());
    
    return ans[k-1];
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    int k = 2; // Example value for k
    cout << "The " << k << "th largest element is: " << kthLargest(root, k) << endl;
    
    return 0;
}