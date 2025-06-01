class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int ans=0,n=mat1.size();
        int s=0,e=(n*n)-1;
        
        while(s<(n*n) && e>=0)
        {
            int r1=s/n,c1=s%n,r2=e/n,c2=e%n;
            
            if(mat1[r1][c1]+mat2[r2][c2]==x)
            {
                ans++;
                s++;
                e--;
            }
            else if(mat1[r1][c1]+mat2[r2][c2]>x)
            {
                e--;
            }
            else 
            {
                s++;
            }
        }
        return ans;
    }
};