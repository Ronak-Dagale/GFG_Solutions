class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
         sort(arr.begin(),arr.end());
        int j = 1;
        int i = 0;
        while(i < arr.size()-1){
            if(arr[i][j] > arr[++i][0]){
                return false;
            }
        }
        
        return true;
        
    }
};