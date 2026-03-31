class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int cash=0,hold=-arr[0];
        
        for(int i=1;i<arr.size();i++){
            int prevcash=cash;
            
            // sell
            cash=max(cash,hold+arr[i]-k);
            
            // buy
            hold=max(hold,prevcash-arr[i]);
        }
        return cash;
    }
};