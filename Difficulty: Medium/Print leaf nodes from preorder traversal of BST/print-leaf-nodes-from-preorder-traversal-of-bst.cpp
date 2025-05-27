class Solution {
  public:
  vector<int> fun(int s,int e,vector<int>& pre)
  {
      if(s==e) return {pre[s]};
      if(s>e) return {};
      
      int curr=pre[s];
      int i=s+1;
      
      while(i<=e && pre[i]<curr) i++;
      
      vector<int>l=fun(s+1,i-1,pre);
      vector<int>r=fun(i,e,pre);
      
      for(auto ele:r) l.push_back(ele);
      return l;
  }
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        int n=preorder.size();
        return fun(0,n-1,preorder);
    }
};