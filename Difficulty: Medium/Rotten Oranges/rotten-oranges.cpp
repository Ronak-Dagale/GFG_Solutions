class Solution {
  public:
  bool rotadj(int x,int y,queue<pair<int,int>>&q,vector<vector<int>>& mat,int &cnt){
      int dx[]={1,0,-1,0};
      int dy[]={0,1,0,-1};
      bool flag=0;
      for(int i=0;i<4;i++){
          int nx=x+dx[i];
          int ny=y+dy[i];
          
          if(nx>=0 && ny>=0 && nx<mat.size() && ny<mat[0].size() && mat[nx][ny]>=0){
              if(mat[nx][ny]==1){
                  cnt--;
                  mat[nx][ny]=-2;
                  q.push(make_pair(nx,ny));
                  flag=1;
              }
          }
      }
      return flag;
  }
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int ans=0,m=mat.size(),n=mat[0].size(),cnt=m*n;
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==2) {
                    cnt--;
                    q.push(make_pair(i,j));
                    mat[i][j]=-2;
                }
                else if(mat[i][j]==0) cnt--; 
            }
        }
        
        while(!q.empty()){
            int s=q.size();
            bool flag=0;
            while(s--){
                auto tmp=q.front();
                q.pop();
                bool z=rotadj(tmp.first,tmp.second,q,mat,cnt);
                if(z)
                flag=1;
            }
            if(flag==1) ans++;
        }
    
        if(cnt==0) return ans;
        
        return -1;
    }
};