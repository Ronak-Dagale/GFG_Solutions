//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            vector<bool>vis(26,0);
            vector<bool>vis1(26,0);
            
            for(int i=0;i<A.size();i++)
            {
                vis[A[i]-'a']=1;
            }
            for(int i=0;i<B.size();i++){
                vis1[B[i]-'a']=1;
            }
            
            string ans="";
            for(int i=0;i<26;i++)
            {
                if(vis[i]!=vis1[i])
                ans.push_back(i+'a');
            }
            if(ans.size()==0)
            return "-1";
            return ans;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends