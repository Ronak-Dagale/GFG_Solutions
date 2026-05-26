class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int cz=0,co=0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) cz++;
        }
        int ans=cz;
        for(int i=0;i<arr.size();i++){
           if(arr[i]==0){
               cz--;
           }
           else{
               co++;
               
           }
           ans=min(ans,cz+co);
        }
        return ans;
    }
};