//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    bool chk(vector<int>&fre1,vector<int>&fre2)
    {
        for(int i=0;i<26;i++)
        {
            if(fre1[i]<fre2[i]) return 0;
        }
        return 1;
    }
    string smallestWindow (string s, string p)
    {
        // Your code her
        string res="";
        int ans=INT_MAX;
        int st=-1;
        int i=0,j=0;
        vector<int>fre2(26,0);
        vector<int>fre1(26,0);
        
        for(int i=0;i<p.size();i++)
        fre2[p[i]-'a']++;
        
        while(j<s.size())
        {
            fre1[s[j]-'a']++;
            if(chk(fre1,fre2))
            {
               while(i<=j && chk(fre1,fre2))
               {
                   fre1[s[i]-'a']--;
                   if(j-i+1<ans)
                  {
                   ans=(j-i)+1;
                   st=i;
                  }
                  i++;
               }
            }
            j++;
        }
        if(ans==INT_MAX) return "-1";
        // cout<<st<<endl;
       return s.substr(st, ans);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends