class Solution {
  public:
  int cntsetbit(int n){
      int res=0;
      while(n!=0){
          if(n&1) res++;
          n=n/2;
      }
      return res;
  }
  static bool cmp(vector<int>&a,vector<int>&b){
      if(a[0]!=b[0]) return b[0]<a[0];
      return a[1]<b[1];
  }
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>v(n,vector<int>(3));
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            v[i][0]=cntsetbit(arr[i]);
            v[i][1]=i;
            v[i][2]=arr[i];
        }
        
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<n;i++){
            ans[i]=v[i][2];
        }
        
        return ans;
    }
};