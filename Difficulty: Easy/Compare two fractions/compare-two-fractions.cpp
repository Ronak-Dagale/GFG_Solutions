//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
          int i=0;
    while(str[i]!='/')
    {
        i++;
    }
    string s1=str.substr(0,i);
    int j=i+1;
    i++;
    while(str[i]!=',')
    {
        i++;
    }
    string s2=str.substr(j,i-j);
    i=i+2;
    j=i;
    while(str[i]!='/')
    {
        i++;
    }
    string s3=str.substr(j,i-j);
     j=i+1;
    i++;
    while(str[i]!='\0')
    {
        i++;
    }
    string s4=str.substr(j,i-j);
    int a=stoi(s1);
    int b=stoi(s2);
    int c=stoi(s3);
    int d=stoi(s4);
    double first=(float)a/b;
    double second=(float)c/d;
    if(first>second)
    {
        string final=s1+"/"+s2;
        return final;
    }
    else if(first<second)
    {
        string final=s3+"/"+s4;
        return final;
    }
    else
    {
        return "equal";
    }
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends