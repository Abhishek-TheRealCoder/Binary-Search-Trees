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
    if(root==NULL)return;
    
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
    return;
}
int floor(Node* root, int x) {
    // Code here
    if(root==NULL) return -1;
    
    vector<int>ans;
    inorder(root,ans);
    int n = ans.size();
    for(int i = n-1;i >= 0;i--){
        if(ans[i] == x) return x;
        if(ans[i] < x) return ans[i]; 
    }
    
    return -1; 
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    int x = 6; // Example value for x
    cout << "The floor of " << x << " is: " << floor(root, x) << endl;
    
    return 0;
}