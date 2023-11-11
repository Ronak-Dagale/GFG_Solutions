//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.size()!=str2.size()) return 0;
        // Your code here
        map<char,pair<char,int>>mp1,mp2;
        for(int i=0;i<str1.size();i++)
        {
             mp1[str1[i]].second++;
             mp1[str1[i]].first='0';
        }
       
        
        for(int i=0;i<str2.size();i++)
        {
             mp2[str2[i]].second++;
             mp2[str2[i]].first='0';
        }
        
        for(int i=0;i<str1.size();i++)
        {
            if(mp1[str1[i]].second==mp2[str2[i]].second)
            {
                if(mp1[str1[i]].first=='0' || mp1[str1[i]].first==str2[i])
                {
                    mp1[str1[i]].first=str2[i];
                }
                else
                return 0;
                
                if(mp2[str2[i]].first=='0' || mp2[str2[i]].first==str1[i])
                {
                    mp2[str2[i]].first=str1[i];
                }
                else
                return 0;
            }
            else 
            return 0;
        }
        return 1;
       
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends