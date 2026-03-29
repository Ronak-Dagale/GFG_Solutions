class Solution {
  public:
 int mod=1e9+7;
    int countPartitions(vector<int>& arr, int d) {
        // Code here
      int s1=0,s2=0,n=arr.size();
        int ans=0;
        long long int sum=0;
        for(int i=0;i<n;i++)
        sum+=arr[i];
        
        vector<int>dp1(sum+1,0);
        vector<int>dp2(sum+1,0);
        dp1[0]=1;
        dp2[0]=1;
        long long int temp=0;
        for(int i=0;i<n;i++)
        {
            temp+=arr[i];
            for(int j=0;j<=temp;j++)
            {
                if(j-arr[i]>=0)
                dp2[j]=(dp1[j]+dp1[j-arr[i]])%mod;
            }
            dp1=dp2;
           
        }
        
        for(int i=0,j=sum;i<=sum;i++,j--)
        {
           if(i-j==d)
           ans=dp1[i];
        }
       
            
        return ans;
        
    }
};