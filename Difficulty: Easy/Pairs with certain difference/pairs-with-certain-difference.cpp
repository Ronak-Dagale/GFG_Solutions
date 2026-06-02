class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int K) {
        // code here
        int N=arr.size();
         sort(arr.begin(),arr.end(),greater<int>());
        int ans=0;
        for(int i=0;i<N;i++)
        {
           if(i+1<N && (arr[i]-arr[i+1])<K)
           {
               ans+=arr[i]+arr[i+1];
               i++;
           }
        }
        return ans;
    }
};