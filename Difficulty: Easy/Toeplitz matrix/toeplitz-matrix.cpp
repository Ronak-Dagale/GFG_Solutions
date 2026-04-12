class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        bool ans=1;
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i+1<m && j+1<n && (mat[i][j]!=mat[i+1][j+1])){
                    ans=0;
                    break;
                }
            }
            if(!ans)
            break;
        }
        return ans;
    }
};