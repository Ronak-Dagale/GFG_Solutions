class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>ans;
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                
                int a1=a[i],b1=b[j];
                while(i<a.size() && a[i]==a1) i++;
                while(j<b.size() && b[j]==b1) j++;
            }
            else if(a[i]<b[j]){
                int a1=a[i];
                while(i<a.size() && a[i]==a1) i++;
            }
            else{
                 int b1=b[j];
                while(j<b.size() && b[j]==b1) j++;
            }
        }
        return ans;
    }
};