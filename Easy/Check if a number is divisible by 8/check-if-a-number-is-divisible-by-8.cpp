//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        if(s.size()<=2)
        {
            int chk=0;
            int temp=1;
            for(int i=s.size()-1;i>=0;i--)
            {
                chk=chk+(s[i]-'0')*temp;
                temp=temp*10;
            }
            return chk%8==0?1:-1;
        }
        else
        {
            int n=s.size();
            int d1=s[n-1]-'0';
            int d2=s[n-2]-'0';
            int d3=s[n-3]-'0';
            
            int chk=0;
            chk=d3*100+d2*10+d1;
            return chk%8==0?1:-1;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends