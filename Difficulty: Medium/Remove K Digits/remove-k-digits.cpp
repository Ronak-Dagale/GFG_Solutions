class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here 5765028321
        string ans="";
        int n=ans.size();
        
        for(int i=0;i<s.size();i++){
            while(!ans.empty() && ans.back()>s[i] && k){
                ans.pop_back();
                k--;
            }
            
            if(s[i]!='0' || ans.size()>0)  ans.push_back(s[i]);
        }
        
         ans = ans.substr(0,max((int)ans.size()-k,0));
        return ans.size()?ans:"0";
    }
};