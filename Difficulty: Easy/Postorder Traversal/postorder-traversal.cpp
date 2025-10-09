/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void solve(Node*r,vector<int>&ans){
      if(!r) return;
      
      solve(r->left,ans);
      solve(r->right,ans);
      ans.push_back(r->data);
  }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};