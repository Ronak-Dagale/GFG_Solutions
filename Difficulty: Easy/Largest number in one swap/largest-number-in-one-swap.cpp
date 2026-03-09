class Solution {
  public:
  int chk(vector<int>fre,int n,int id){
      int res=-1;
      for(int i=n+1;i<10;i++){
          if(fre[i]>id) res=fre[i];
      }
      return res;
  }
    string largestSwap(string &s) {
        // code here
        vector<int>fre(10,0);
        for(int i=0;i<s.size();i++){
            fre[s[i]-'0']=i;
        }
        
        for(int i=0;i<s.size();i++){
            int ex=chk(fre,s[i]-'0',i);
            if(ex!=-1)
            {
                swap(s[i],s[ex]);
                return s;
            }
        }
        return s;
    }
};