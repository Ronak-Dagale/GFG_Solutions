class Solution {
  public:
    int minSteps(vector<int>& arr, int s, int e) {
        // code here
        int mod=1000;
        vector<int>dist(mod,-1);
        queue<int>q;
        s=s%mod;
        e=e%mod;
        
        dist[s]=0;
        q.push(s);
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            
            if(curr==e){
                return dist[curr];
            }
            
            for(int i=0;i<arr.size();i++){
                int ne=(arr[i]*curr)%mod;
                
                if(dist[ne]==-1){
                    q.push(ne);
                    dist[ne]=dist[curr]+1;
                }
            }
        }
        return -1;
        
    }
};