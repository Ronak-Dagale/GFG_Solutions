class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int ans=0,n=arr.size();
        long sum1=0,sum2=0;
        long tmp1=0,tmp2=0;
        
        for(int i=0;i<n;i++){
            if(i&1) sum1+=arr[i];
            else sum2+=arr[i];
        }
        // cout<<sum1<<" "<<sum2<<endl;
        for(int i=0;i<n;i++){
            if(i&1){
                if(sum1-arr[i]-tmp1+tmp2==sum2-tmp2+tmp1) ans++;
                // cout<<sum1-arr[i]-tmp1+tmp2<<" "<<sum2-tmp2+tmp1<<endl;
            }
            else{
                if(sum2-arr[i]-tmp2+tmp1==sum1-tmp1+tmp2) ans++;
                // cout<<sum2-arr[i]-tmp2+tmp1<<" "<<sum1-tmp1+tmp2<<endl;
            }
            
             if(i&1) tmp1=tmp1+arr[i];
            else tmp2=tmp2+arr[i];
        }
        return ans;
    }
};