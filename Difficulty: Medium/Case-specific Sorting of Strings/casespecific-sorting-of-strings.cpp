class Solution {
  public:
    string caseSort(string& s) {
        // code here
        vector<int>upper(26,0),lower(26,0);
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            upper[s[i]-'A']++;
            else
            lower[s[i]-'a']++;
        }
        
        int i=0,j=0;
        for(int k=0;k<s.size();k++)
        {
            if(s[k]>='A' && s[k]<='Z')
            {
               while(upper[i]==0) i++;
               
               ans.push_back('A'+i);
               upper[i]--;
            }
            else
            {
                while(lower[j]==0) j++;
                
                ans.push_back('a'+j);
                lower[j]--;
            }
        }
        return ans;
    }
};