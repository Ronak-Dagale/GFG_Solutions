class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<int>ans;
        vector<int>ind(n,0);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<prerequisites.size();i++){
            ind[prerequisites[i][0]]++;
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto i:mp[front]){
                ind[i]--;
                if(ind[i]==0) q.push(i);
            }
        }
        
        if(ans.size()==n) return ans;
        return {};
    }
};