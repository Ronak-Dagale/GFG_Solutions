/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
  void solve(Node*r,map<int,int>&mp,int l){
      if(!r) return;
      
       mp[l]+=r->data;
      solve(r->left,mp,l-1);
      solve(r->right,mp,l+1);
  }
    vector<int> verticalSum(Node* root) {
        // code here
        map<int,int>mp;
        solve(root,mp,0);
        vector<int>ans;
        for(auto m:mp){
            ans.push_back(m.second);
        }
        return ans;
    }
};