class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string>ans;
        ans.push_back("1");
        
        for(int i=1,x=0,j=0;i<n;i++){
            ans.push_back(ans[j]+to_string(x));
            x^=1;
            if(x==0) j++;
        }
        return ans;
    }
};