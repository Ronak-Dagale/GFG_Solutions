class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int ans=0;
        int prev=0;
        
        for(int i=0;i<s.size();i++)
        {
            int tmp=(prev*10)+((s[i]-'0')*(i+1));
            prev=tmp;
            ans+=tmp;
        }
        return ans;
    }
};