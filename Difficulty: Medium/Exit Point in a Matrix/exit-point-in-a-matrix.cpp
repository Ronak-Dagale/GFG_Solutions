class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        vector<int>ans;
        int x=0,y=0,k=3;
        ans.push_back(x);
        ans.push_back(y);
        int dx[]={1,0,-1,0};
        int dy[]={0,-1,0,1};
        
        int n=mat.size(),m=mat[0].size();
        while(x>=0 && y>=0 && x<n && y<m){
            // cout<<x<<" "<<y<<endl;
            ans[0]=x,ans[1]=y;
            int nx=0,ny=0;
            if(mat[x][y]==0){
                nx=x+dx[k];
                ny=y+dy[k];
            }
            else{
                k++;
                k=k%4;
                nx=x+dx[k];
                ny=y+dy[k];
                mat[x][y]=0;
            }
            x=nx,y=ny;
        }
        return ans;
    }
};