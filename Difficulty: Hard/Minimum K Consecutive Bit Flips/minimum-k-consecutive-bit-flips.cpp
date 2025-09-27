class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n=arr.size(),times=0,i=0,ans=0;
        vector<bool>flip(n,0);
        
        for (int i = 0; i < n; i++) {
        if (i >= k && flip[i - k]) times--;

        if ((arr[i] == 0 && times % 2 == 0) || (arr[i] == 1 && times % 2 == 1)) {
            if (i + k > n) return -1;
            flip[i] = true;
            times++;
            ans++;
        }
    }

    return ans;
    }
};