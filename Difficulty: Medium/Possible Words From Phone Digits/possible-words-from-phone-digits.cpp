class Solution {
  public:
    void solve(vector<int> &a,int n, vector<string>&mp, vector<string>&ans,string temp,int id)
    {
        if(id>=n)
        {
            ans.push_back(temp);
            return;
        }
        
        string z=mp[a[id]];
        
        for(int i=0;i<z.size();i++)
        {
            if(z[i]!=' ')
            temp.push_back(z[i]);
            solve(a,n,mp,ans,temp,id+1);
            if(z[i]!=' ')
            temp.pop_back();
        }
    }
    vector<string> possibleWords(vector<int> &a) {
        // code here
        vector<string>mp={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        int n=a.size();
        string temp="";
        solve(a,n,mp,ans,temp,0);
        return ans;
    }
};