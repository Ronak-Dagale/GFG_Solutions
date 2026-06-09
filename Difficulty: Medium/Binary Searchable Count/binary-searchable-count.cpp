class Solution {
  public:
  void solve(vector<int>& arr,int l,int r,int low,int high,int &ans){
      if(l>r) return;
      
      int mid=(l+r)/2;
      if(arr[mid]>low && arr[mid]<high) ans++;
      
      solve(arr,l,mid-1,low,min(high,arr[mid]),ans);
      solve(arr,mid+1,r,max(low,arr[mid]),high,ans);
  }
    int binarySearchable(vector<int>& arr) {
        // code here
        int ans=0;
        solve(arr,0,arr.size()-1,INT_MIN,INT_MAX,ans);
        return ans;
    }
};