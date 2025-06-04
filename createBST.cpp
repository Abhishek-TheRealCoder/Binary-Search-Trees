
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

Node*createBST(Node*& root,int val){
    if(root == NULL){
        return new Node(val);
    }
    
    if(root->data > val){
        root->left = createBST(root->left,val);
    }else{
        root->right = createBST(root->right,val);
    }
    
    return root;
}


void buildBST(Node*&root){
    int data;
    cout<<"enter the data to insert : ";
    cin>>data;
    
    while(data!=-1){
        root = createBST(root,data);
        cout<<"enter the data to insert : ";
        cin>>data;
    }
}

void inorder(Node*root){
    if(root==NULL) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node*root = NULL;
    buildBST(root);
    
    inorder(root);
    return 0;
}