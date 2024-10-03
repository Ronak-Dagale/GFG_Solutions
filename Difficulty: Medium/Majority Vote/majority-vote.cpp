//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int c1=0,c2=0,r1=0,r2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==r1) c1++;
            else if(nums[i]==r2) c2++;
            else if(c1==0){
                c1++;
                r1=nums[i];
            }
            else if(c2==0)
            {
                c2++;
                r2=nums[i];
            }
            else
            {
                c1--;
                c2--;
            }
        }
        
        vector<int>ans;
        c1=c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==r1) c1++;
            if(nums[i]==r2) c2++;
        }
        if(c1>nums.size()/3) ans.push_back(r1);
        if(c2>nums.size()/3) ans.push_back(r2);
        if(ans.size()==0) return {-1};
        if(ans.size()==2 && ans[0]>ans[1])
        swap(ans[0],ans[1]);
        
        return ans;
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
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends