//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            int s1=0,s2=0;
            int b1=INT_MAX,b2=INT_MAX;
            
            for(int i=0;i<price.size();i++)
            {
                b1=min(b1,price[i]);
                s1=max(s1,price[i]-b1);
                b2=min(b2,price[i]-s1);
                s2=max(s2,price[i]-b2);
            }
            return s2;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends