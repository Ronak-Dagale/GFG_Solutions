//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int>ans;
        unordered_map<int,bool>mp;
        
        int i=0,j=0;
        while(i<a.size() && j<b.size())
        {
            if(a[i]<b[j])
            {
                if(!mp[a[i]])
                ans.push_back(a[i]);
                
                mp[a[i]]=1;
                i++;
            }
            else
            {
                if(!mp[b[j]])
                ans.push_back(b[j]);
                
                mp[b[j]]=1;
                j++;
            }
        }
        while(i<a.size())
        {
          if(!mp[a[i]])
                ans.push_back(a[i]);
                
                mp[a[i]]=1;
                i++;  
        }
        while(j<b.size())
        {
            if(!mp[b[j]])
                ans.push_back(b[j]);
                
                mp[b[j]]=1;
                j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends