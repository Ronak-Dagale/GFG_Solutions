class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int mini=0,maxi=0,n=prices.size();
        sort(prices.begin(),prices.end());
        
        int i=0,j=n-1;
        while(i<=j)
        {
          mini+=prices[i];
          i++;
          j=j-k;
        }
        i=0,j=n-1;
        while(i<=j)
        {
            maxi+=prices[j];
            j--;
            i=i+k;
        }
        return {mini,maxi};
    }
};