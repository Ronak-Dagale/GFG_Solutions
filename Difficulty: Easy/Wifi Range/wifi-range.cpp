class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int cnt=0,cap=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') {
                cnt--;
                if(abs(cnt)>x) return 0;
            }
            else{
                cnt=x;
            }
        }
        return cnt>=0;
    }
};