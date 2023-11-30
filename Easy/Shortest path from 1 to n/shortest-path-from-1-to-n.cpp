//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minimumStep(int n){
        //complete the function here
        if(n==1) return 1;
        
        int ans=0;
       while(n!=0)
       {
          // cout<<n<<endl;
          if(n%3==0)
          {
              n=n/3;
              ans++;
          }
          else
          {
              n=n-1;
              ans++;
          }
       }
       
       return ans-1;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends