class Solution {
  public:
  bool poss(int mid,vector<int>& arr, int k){
      int t=0;
      for(int i=0;i<arr.size();i++){
          int tmp=arr[i]/mid;
          if(arr[i]%mid!=0) tmp++;
          t=t+tmp;
          
          if(t>k) return 0;
      }
      return 1;
  }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int s=1,e=arr.size();
        for(int i=0;i<arr.size();i++){
            s=min(s,arr[i]);
            e=max(e,arr[i]);
        }
        
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(poss(mid,arr,k)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};