class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        int n=high-low+1;
        vector<bool>fre(n,0);
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=low && arr[i]<=high){
                fre[arr[i]-low]=1;
            }
        }
        
        for(int i=0;i<n;i++){
            if(!fre[i]) ans.push_back(low+i);
        }
        return ans;
    }
};