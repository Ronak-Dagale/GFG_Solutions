class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
       sort(a.begin(),a.end());
       int ans=INT_MAX;
       
       for(int i=0,j=m-1;j<a.size();i++,j++){
           ans=min(ans,a[j]-a[i]);
       }
       return ans;
    }
};