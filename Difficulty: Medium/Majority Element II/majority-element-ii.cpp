//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int c1=0,c2=0,n1=0,n2=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==n1) c1++;
            else if(arr[i]==n2) c2++;
            else if(c1==0){
                c1++;
                n1=arr[i];
            }
            else if(c2==0)
            {
                c2++;
                n2=arr[i];
            }
            else
            {
                c1--;
                c2--;
            }
        }
        
        c1=c2=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==n1) c1++;
            else if(arr[i]==n2) c2++;
        }
        if(c1>(arr.size()/3) && c2>(arr.size()/3))
        {
            if(n1>n2) return {n2,n1};
            return {n1,n2};
        }
        if(c1>(arr.size()/3))
        return {n1};
        if(c2>(arr.size()/3))
        return {n2};
        
        return {};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends