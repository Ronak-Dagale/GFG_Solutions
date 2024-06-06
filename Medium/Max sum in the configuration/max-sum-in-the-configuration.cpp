//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long sum=0,temp=0;
        for(long long i=0;i<n;i++)
        {
            sum+=a[i];
            temp+=i*a[i];
        }
        long long ans=temp;
        
        for(long long i=1;i<n;i++)
        {
            temp=temp-sum+(long long)a[i-1]*n;
            ans=max(ans,temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends