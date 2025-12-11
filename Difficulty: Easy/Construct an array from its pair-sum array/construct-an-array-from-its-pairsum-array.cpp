class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        // code here
        vector<int>ans;
         int m=arr.size();
        int n=( 1 + sqrt(1+8*m) )/2;

        int r0=(arr[0]+arr[1]-arr[n-1])/2;
        ans.push_back(r0);
        for(int i=1;i<n;i++){
            ans.push_back(arr[i-1]-ans[0]);
        }
       
        return ans;
    }
};