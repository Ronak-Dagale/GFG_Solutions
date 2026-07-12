class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        int mod=1e9+7;
        int ans=0;
        priority_queue<int>q;
        for(int i=0;i<arr.size();i++){
            q.push(arr[i]);
        }
        
        while(!q.empty() && k>0){
            int top=q.top();
            // cout<<top<<endl;
            q.pop();
            
            ans=((ans%mod)+(top%mod))%mod;
            k--;
            if(top-1!=0)
            q.push(--top);
        }
        return ans%mod;
    }
};