//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
 static bool cmp(pair<int,int> a, pair<int,int> b){
        // activity with small end time can be perform first
        return a.second < b.second ;  
    }
  
    int activitySelection(vector<int> &start, vector<int> &end) {
        // Think Greedy - Sort activities on basis of end time

        vector<pair<int,int>> activity ;
        for(int i = 0 ; i < start.size() ; i++){
            activity.push_back(make_pair(start[i],end[i])) ;
        }
        // By default pair is sorted on basis of first argument
        // so use custom comparator
        sort(activity.begin(),activity.end(), cmp) ;
        int count = 1 ;   // first activity has to be performed
        int ansEnd = activity[0].second ; //End time of selected activity
        for(int i = 0 ; i < activity.size() ; i++){
            // activity with small end time can be perform first
            if(activity[i].first > ansEnd){
                count++ ;
                ansEnd = activity[i].second ; 
            }
        }
        return count ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends