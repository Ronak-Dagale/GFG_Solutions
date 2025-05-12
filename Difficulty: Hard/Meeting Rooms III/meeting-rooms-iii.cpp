//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        sort(meetings.begin(),meetings.end());
        
        priority_queue<int,vector<int>,greater<int>>q1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q2;
        
        for(int i=0;i<n;i++)
        q1.push(i);
        
        vector<int>cnt(n,0);
        
        for(auto i:meetings)
        {
            while(!q2.empty() && q2.top().first<=i[0])
            {
                q1.push(q2.top().second);
                q2.pop();
            }
            
            if(!q1.empty())
            {
                cnt[q1.top()]++;
                q2.push({i[1],q1.top()});
                q1.pop();
            }
            else
            {
                auto it=q2.top();
                q2.pop();
                
                cnt[it.second]++;
                int d=i[1]-i[0];
                q2.push({it.first+d,it.second});
            }
        }
         int ans=-1;
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(cnt[i]>res)
            {
                res=cnt[i];
                ans=i;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends