//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        sort(a,a+n);
        sort(b,b+m);
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++)sum1+=a[i];
        for(int j=0;j<m;j++) sum2+=b[j];
        
        if(sum1==sum2) return 1;
        else if(sum1<sum2)
        {
            int i=0,j=m-1;
            while(i<n && j>=0 && a[i]<b[j])
            {
                int temp1=sum1-a[i]+b[j];
                int temp2=sum2-b[j]+a[i];
                if(temp1==temp2) return 1;
                else if(temp2<temp1) j--;
                else i++;
            }
        }
        else
        {
            int i=n-1,j=0;
            while(i>=0 && j<m && a[i]>b[j])
            {
                int temp1=sum1-a[i]+b[j];
                int temp2=sum2-b[j]+a[i];
                if(temp1==temp2) return 1;
                else if(temp1<temp2) i--;
                else j++;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends