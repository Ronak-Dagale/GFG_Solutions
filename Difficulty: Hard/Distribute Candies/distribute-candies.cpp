/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  int solve(Node*r,int&ans){
      if(!r) return 0;
      
      int la=solve(r->left,ans);
      int ra=solve(r->right,ans);
      
      ans=ans+abs(la)+abs(ra);
      return r->data-1+la+ra;
  }
    int distCandy(Node* root) {
        // code here
        int ans=0;
        solve(root,ans);
        return ans;
    }
};