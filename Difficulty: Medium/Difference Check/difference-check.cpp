class Solution {
  public:
  int solve1(char a,char b)
  {
      int num=((a-'0')*10)+(b-'0');
      return num*3600;
  }
   int solve2(char a,char b)
  {
      int num=((a-'0')*10)+(b-'0');
      return num*60;
  }
   int solve3(char a,char b)
  {
      int num=((a-'0')*10)+(b-'0');
      return num;
  }
    int minDifference(vector<string> &arr) {
        // code here
        int ans=INT_MAX,n=arr.size();
        vector<int>sec(n);
        
        for(int i=0;i<n;i++){
            sec[i]=solve1(arr[i][0],arr[i][1]);
            sec[i]+=solve2(arr[i][3],arr[i][4]);
            sec[i]+=solve3(arr[i][6],arr[i][7]);
        }
        sort(sec.begin(),sec.end());
        
        for(int i=0;i<n;i++){
           ans=min(ans,abs(sec[i]-sec[(i+1)%n]));
        }
        ans=min(ans,86400-sec[n-1]+sec[0]);
        return ans;
    }
};
