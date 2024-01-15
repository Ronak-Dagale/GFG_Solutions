//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> v ,int N) {
        // code here
        for(int i=N-1;i>=0;i--)
        {
           if(i==N-1)
           v[i]++;
           
           if(v[i]==10)
           {
               v[i]=0;
               if(i!=0)
               {
                   v[i-1]++;
               }
               else
               {
                   v.push_back(0);
                   v[i]=1;
               }
               
           }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends