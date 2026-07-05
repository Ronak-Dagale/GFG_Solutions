class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        int ans=INT_MIN;
        vector<int>fre(26,-1);
        for(int i=0;i<s.size();i++){
            if(fre[s[i]-'a']==-1){
                fre[s[i]-'a']=i;
            }
            // cout<<fre[s[i]-'a']<<endl;
            if(fre[s[i]-'a']!=-1)
            ans=max(ans,i-fre[s[i]-'a']-1);
        }
        return ans==INT_MAX?-1:ans;
    }
};