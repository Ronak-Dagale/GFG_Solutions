
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++)
        mp[arr[i]]++;
        
        vector<int>ans;
        for(int i=k,j=0;i<arr.size();i++,j++)
        {
            ans.push_back(mp.size());
            mp[arr[j]]--;
            if(mp[arr[j]]==0)
            mp.erase(arr[j]);
            
            mp[arr[i]]++;
        }
        ans.push_back(mp.size());
        return ans;
    }
};
