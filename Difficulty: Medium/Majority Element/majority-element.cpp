//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int ans=arr[0];
        int cnt=0;
        if(arr.size()==1) return ans;
        for(int i=0;i<arr.size();i++)
        {
            if(cnt==0) {
                ans=arr[i];
            }
            
            if(ans==arr[i])
            cnt++;
            else 
            cnt--;
        }
        
        cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            if(ans==arr[i])
            cnt++;
        }
        
        return cnt>(arr.size()/2)?ans:-1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends