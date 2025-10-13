/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    pair<int,int> solve(Node*root)
    {
        if(!root)
        return {0,0};
        
        pair<int,int>l=solve(root->left);
        pair<int,int>r=solve(root->right);
        
        pair<int,int> res;
        res.first=root->data+l.second+r.second;
        res.second=max(l.first,l.second)+max(r.first,r.second);
        
        return res;
        
    }
    int getMaxSum(Node *root) {
        // code here
        pair<int,int>ans=solve(root);
        return max(ans.first,ans.second);
    }
};