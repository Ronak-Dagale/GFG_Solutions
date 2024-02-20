//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
bool solve(string s,int id,vector<string> &d)
{
    if(id==s.size())
    return 1;
    
    int ans=0;
    for(int i=0;i<d.size();i++)
    {
        if(s[id]==d[i][0])
        {
            int p=id;
            int k=0;
            while(k<d[i].size() && p<s.size() && d[i][k]==s[p])
            {
                k++;
                p++;
            }
            ans=ans|solve(s,p,d);
        }
    }
    return ans;
}
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
     return solve(s,0,dictionary);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends