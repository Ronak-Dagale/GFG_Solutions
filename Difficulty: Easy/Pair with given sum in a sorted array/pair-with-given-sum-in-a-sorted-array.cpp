//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function3
        int ans=0;
        int s=0,e=arr.size()-1;
        while(s<e)
        {
            int sum=arr[s]+arr[e];
            if(sum==target)
            {
                ans++;
                int nexts=s+1;
                while(nexts<e && arr[nexts]==arr[s])
                {
                    ans++;
                    nexts++;
                }
                e--;
            }
            else if(sum<target) s++;
            else e--;
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
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends