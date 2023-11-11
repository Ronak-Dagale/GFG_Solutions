//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        int cnt1=INT_MIN;
        for(auto v:mp)
        {
            if(cnt1<v.second)
            {
                cnt1=v.second;
            }
        }
        
        int cnt2=INT_MIN;
        for(auto v:mp)
        {
            if(cnt2<v.second && v.second!=cnt1)
            {
                cnt2=v.second;
            }
            
        }
        for(auto v:mp)
        {
            if(v.second==cnt2)
            return v.first;
        }
        
        return "";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends