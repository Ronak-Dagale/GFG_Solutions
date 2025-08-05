class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int i=0,j=s.size()-1;
        while(i<=j)
        {
          
            if((s[i]>='A' && s[i]<='Z'))
            s[i]=s[i]+32;
            if(s[j]>='A' && s[j]<='Z')
            s[j]=s[j]+32;
            
            while(!(s[i]>='a' && s[i]<='z') && i<=j && !(s[i]>='0' && s[i]<='9'))
            {
                i++;
                 if((s[i]>='A' && s[i]<='Z'))
                 s[i]=s[i]+32;
            }
            
            while(!(s[j]>='a' && s[j]<='z') && i<=j && !(s[j]>='0' && s[j]<='9'))
            {j--;
               if(s[j]>='A' && s[j]<='Z')
            s[j]=s[j]+32; 
            }
            
            if((s[i]>='A' && s[i]<='Z'))
            s[i]=s[i]+32;
            if(s[j]>='A' && s[j]<='Z')
            s[j]=s[j]+32;
            
      
            if(i<j && s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
};