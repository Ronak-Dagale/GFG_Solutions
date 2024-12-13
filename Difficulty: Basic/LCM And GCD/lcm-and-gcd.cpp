//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        int ele1=a,ele2=b;

        while(ele1>0 && ele2>0)
        {
            if(ele1>ele2)
            ele1=ele1%ele2;
            else
            ele2=ele2%ele1;
        }
        int ans2,ans1;
        if(ele1==0) 
        ans2=ele2;
        else
        ans2=ele1;
        
        ans1=(a*b)/ans2;
        
        return {ans1,ans2};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends