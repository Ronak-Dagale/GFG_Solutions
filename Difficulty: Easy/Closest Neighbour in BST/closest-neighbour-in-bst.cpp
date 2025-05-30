/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
 void solve(Node* root, int n,int&ans)
  {
      if(!root)return;
      
      if(root->data<=n)
      {
          ans=max(ans,root->data);
      }
      
      
      solve(root->right,n,ans);
      solve(root->left,n,ans);
  }
    int findMaxFork(Node* root, int k) {
        // code here
      int ans=-1;
        solve(root,k,ans);
        return ans;
    }
};