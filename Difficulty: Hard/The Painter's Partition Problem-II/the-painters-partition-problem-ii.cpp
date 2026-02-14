class Solution {
  public:
  bool poss(long long mid,vector<int>& arr, int k){
      int cnt=1;
      int sum=0;
      for(int i=0;i<arr.size();i++){
          sum+=arr[i];
          if(sum>mid){
              cnt++;
              if(arr[i]>mid) return 0;
              sum=arr[i];
          }
          if(cnt>k) return 0;
      }
      return cnt<=k;
  }
    int minTime(vector<int>& arr, int k) {
        // code here
        long long s=INT_MAX,e=0;
        for(int i=0;i<arr.size();i++){
            s=min(s,(long long)arr[i]);
            e=e+arr[i];
        }
        int ans=0;
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(poss(mid,arr,k)){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};