/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
  bool solve(Node*root,int mini,int maxi=INT_MAX)
  {
      if(!root) return 0;
      
      if(!root->left && !root->right)
      {
          if(root->data+1==maxi && root->data-1==mini)
          return 1;
          else 
          return 0;
      }
      
      return solve(root->left,mini,root->data) || solve(root->right,root->data,maxi);
  }
    bool isDeadEnd(Node *root) {
        // Code here
        return solve(root,0,root->data) || solve(root,root->data);
    }
};