class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        int s=1,e=m*n,ans=-1;
        
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            
            int cnt=0;
            for(int i=1;i<=m;i++)
            cnt+=min(mid/i,n);
            
            if(cnt>=k)
            {
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};
