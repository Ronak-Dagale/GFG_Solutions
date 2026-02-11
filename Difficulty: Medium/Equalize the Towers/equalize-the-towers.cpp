class Solution {
  public:
  int val(vector<int>& heights, vector<int>& cost,int mid){
      int res=0;
      for(int i=0;i<heights.size();i++){
          res=res+abs(heights[i]-mid)*cost[i];
      }
      return res;
  }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int s=heights[0],e=heights[0];
        for(int i=0;i<heights.size();i++){
            s=min(heights[i],s);
            e=max(heights[i],e);
        }
        while(s<e){
            int mid=(s+e)/2;
            
            int c1=val(heights,cost,mid);
            int c2=val(heights,cost,mid+1);
            
            if(c1>c2){
                s=mid+1;
            }
            else
            e=mid;
        }
        return val(heights,cost,s);
    }
};
