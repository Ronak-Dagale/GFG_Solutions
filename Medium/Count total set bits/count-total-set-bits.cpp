//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
 {
        // base case
        if(n==0) return 0;
        
        // for 11 -> 8 (2^3)
        // for 19 -> 16 (2^4) 
        int x=largestpow(n);
        
        // upto 8 number of set bits
        // upto 16 number of set bits
        int ans1=(1<<(x-1))*x;
        int ans2=n-(1<<x)+1;
        
        int p=ans2-1;
        return ans1+ans2+countSetBits(p);
    }
    
    int largestpow(int n)
    {
        int ans=0;
        
        while((1<<ans)<=n)
        ans++;
        
        return ans-1;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends