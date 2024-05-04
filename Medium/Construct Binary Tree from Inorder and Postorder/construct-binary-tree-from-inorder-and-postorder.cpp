//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    int find(int in[],int inos,int inoe,int ele)
{
    for(int i=inos;i<=inoe;i++)
    {
        if(in[i]==ele) return i;
    }
    return -1;
}
Node *solve(int in[],int post[],int &posi,int inos,int inoe,int n)
{
    if(posi<0 || inos>inoe)
    return NULL;
    
    int ele=post[posi--];
    Node *root=new Node(ele);
    
    int z=find(in,inos,inoe,ele);
    
   
    root->right=solve(in,post,posi,z+1,inoe,n);
     root->left=solve(in,post,posi,inos,z-1,n);
    
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int posi=n-1;
    int inos=0,inoe=n-1;
    
    return solve(in,post,posi,inos,inoe,n);
}
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends