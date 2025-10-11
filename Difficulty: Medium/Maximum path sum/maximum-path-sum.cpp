/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  vector<int> solve(Node*root,int &ans){
      if(!root) {
          return {0,0,0};
      }
      
      vector<int>l=solve(root->left,ans);
      vector<int>r=solve(root->right,ans);
      
      vector<int>res(3,0);
      res[1]=root->data;
      res[0]=max(l[0],max(l[1],l[2]))+root->data;
      res[2]=max(r[0],max(r[1],r[2]))+root->data;
      
      int rmaxi=max(r[0],max(r[1],r[2]));
      int lmaxi=max(l[0],max(l[1],l[2]));
      ans=max(ans,max(root->data,max(lmaxi+root->data,max(rmaxi+root->data,lmaxi+rmaxi+root->data))));
      return res;
      
  }
    int findMaxSum(Node *root) {
        // code here
        int ans=INT_MIN;
        vector<int>res=solve(root,ans);
        // cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
        ans=max(ans,max(res[0],max(res[1],res[2])));
        return ans;
    }
};