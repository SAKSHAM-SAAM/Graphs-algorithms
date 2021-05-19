#include<bits/stdc++.h>
using namespace std;
// Node class 

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int key)
        {
            this->data=key;
            this->left=this->right=NULL;
        }
};

// Solution of the question

class Solution{
    private:
    int index;
    int search(int in[],int inS,int inE,int data)
    {
        for(int i=inS;i<=inE;i++)
        {
            if(in[i]==data)
            {
                return i;
            }
        }
    }
    
    Node* build(int in[],int pre[],int inS,int inE)
    {
        if(inS>inE) return NULL;
        Node* tmp=new Node(pre[index]);
        index++;
        if(inS==inE) return tmp;
        int inI = search(in,inS,inE,tmp->data);
        
        tmp->left=build(in,pre,inS,inI-1);
        tmp->right=build(in,pre,inI+1,inE);
        
        return tmp;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        index=0;
        Node* root=build(in,pre,0,n-1);
        return root;
    }
};

// printing the post order

void postorder(Node* root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
// 
int main()
{
    int t;cin>>t;
    while(t--);
    {
        int n;
        cin>>n;
        int in[n];
        int pre[n];
        for(int i=0;i<n;i++)
        {
            cin>>in[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>pre[i];
        }
        Solution obj;
        Node* root=obj.buildTree(in,pre,n);
        postorder(root);
    }
    return 0;
}