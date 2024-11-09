//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        string n1,n2;
        for(int i=0;i<arr.size();i++)
        {
            if(i&1)
            n2.push_back(arr[i]+'0');
            else
            n1.push_back(arr[i]+'0');
        }
         string ans;
         int c=0;
         int i=n1.size()-1,j=n2.size()-1;
         
         while(i>=0 && j>=0)
         {
             int sum=c+(n1[i]-'0')+(n2[j]-'0');
             c=sum/10;
             sum=sum%10;
             
             ans.push_back(sum+'0');
             i--;
             j--;
         }
         while(i>=0)
         {
             int sum=c+(n1[i]-'0');
             c=sum/10;
             sum=sum%10;
             
             ans.push_back(sum+'0');
             i--;
         }
         
         while(j>=0)
         {
             int sum=c+(n2[j]-'0');
             c=sum/10;
             sum=sum%10;
             
             ans.push_back(sum+'0');
             j--;
         }
         
         if(c>0)
         ans.push_back(c+'0');
         
         reverse(ans.begin(),ans.end());
         string res;
         i=0;
         
         while(i<ans.size() && ans[i]=='0')
         i++;
         
         while(i<ans.size())
         res.push_back(ans[i++]);
         
         return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends