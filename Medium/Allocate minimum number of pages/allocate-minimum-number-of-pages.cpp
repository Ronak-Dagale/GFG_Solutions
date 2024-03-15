//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isposs(int A[], int N, int M,int mid)
    {
        int cnt=1;
        int sum=0;
        for(int i=0;i<N;i++)
        {
          if(sum+A[i]<=mid)
          {
              sum=sum+A[i];
          }
          else
          {
              cnt++;
              sum=A[i];
              if(sum>mid) return 0;
              if(cnt>M) return 0;
          }
        }
       return 1;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        int ans=-1;
        int s=0;
        int e=0;
       
        for(int i=0;i<N;i++)
        e=e+A[i];
        
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            
            if(isposs(A,N,M,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends