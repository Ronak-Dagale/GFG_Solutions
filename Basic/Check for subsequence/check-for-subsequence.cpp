//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{ 
    public:
    bool isSubSequence(string s, string t) 
    {
        // code here
         if(s.size()==0) return 1;
        int i=0;
        
        for(int j=0;j<t.size();j++)
        {
           if(s[i]==t[j])
               i++;
            
            if(i==s.size())
                return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 

// } Driver Code Ends
