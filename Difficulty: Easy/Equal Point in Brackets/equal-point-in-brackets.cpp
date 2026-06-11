class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int c=0,o=0;
        for(int i=0;i<s.size();i++)  {
            if(s[i]==')') c++;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                if(o==c) return i;
                c--;
            }
            else{
                if(o==c) return i;
                o++;
            }
            
        }
        return (o==c)?s.size():-1;
    }
};