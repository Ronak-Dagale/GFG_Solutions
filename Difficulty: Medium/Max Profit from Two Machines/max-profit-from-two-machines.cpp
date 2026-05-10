class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
          int ans=0,n=arr.size();
       vector<pair<int,int>>fre;
       for(int i=0;i<n;i++)
         fre.push_back({arr[i]-brr[i],i});
         
         sort(fre.begin(),fre.end());
         reverse(fre.begin(),fre.end());
         
         for(int i=0;i<n;i++)
         {
             if(fre[i].first>=0)
             {
                 if(x!=0)
                 {
                    ans+=arr[fre[i].second];
                    x--;
                 }
                 else
                 {
                     ans+=brr[fre[i].second];
                     y--;
                 }
             }
             else
             {
                  if(n-i<=y)
                {
                    ans=ans+brr[fre[i].second];
                    y--;
                }
                else{
                    ans=ans+arr[fre[i].second];
                    x--;
                }
             }
         }
         return ans;
    }
};