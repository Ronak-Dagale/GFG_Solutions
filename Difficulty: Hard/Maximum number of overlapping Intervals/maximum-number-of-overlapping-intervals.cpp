class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        vector<int>s(n),e(n);

        for(int i=0;i<n;i++){
            s[i]=arr[i][0];
            e[i]=arr[i][1];
        }
        sort(s.begin(),s.end());       
        sort(e.begin(),e.end());

        int i=0,j=0,ans=0,cnt=0;
        while(i<n && j<n){
            if(s[i]<=e[j]){
                cnt++;
                ans=max(ans,cnt);
                i++;
            }
            else{
                cnt--;
                j++;
            }
        }
        return ans;
    }
};
