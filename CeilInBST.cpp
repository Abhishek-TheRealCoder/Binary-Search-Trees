
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
int findCeil(Node* root, int input) {
    // Your code here
    if (root == NULL) return -1;
    vector<int>ans;
    inorder(root,ans);
    

    for(int i=0;i<ans.size();i++){
        if(ans[i]==input){
            return ans[i];
        }    
        if(ans[i]>input){
            return ans[i];
        }
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

    int input = 6; // Example value for input
    cout<< "The ceil of " << input << " is: " << findCeil(root, input) << endl;
    return 0;
}