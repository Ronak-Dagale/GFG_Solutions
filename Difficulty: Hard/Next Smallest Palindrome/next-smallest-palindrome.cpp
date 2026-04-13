class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        // code here
        int n=num.size();
        vector<int>ans;
	    int carry;
	    int done=0;
	    
	    for(int i=n/2;i<n;i++)
	    {
	        if(num[i]<num[n-1-i])
	        {
	            num[i]=num[n-1-i];
	            for(int j=i+1;j<n;j++)
	            {
	                num[j]=num[n-1-j];
	                
	            }
	            done=1;
	            break;
	        }
	        else if(num[i]>num[n-1-i])
	        break;
	    }
	    if(done==1)
	    {
	        for(int i=0;i<n;i++)
	        ans.push_back(num[i]);
	        return ans;
	    }
	    carry=1;
	    for(int i=(n-1)/2;i>=0;i--)
	    {
	        if(num[i]+carry==10)
	        {
	            num[i]=0;
	            carry=1;
	        }
	        else
	        {
	            num[i]++;
	            carry=0;
	            break;
	        }
	    }
	    
	    if(carry==1)
	    ans.push_back(1);
	    
	    for(int i=0;i<n;i++)
	        ans.push_back(num[i]);
	        
	        if(carry) n++;
	        
	        for(int i=(n+1)/2;i<n;i++)
	        {
	            ans[i]=ans[n-1-i];
	        }
	        return ans;
    }
};