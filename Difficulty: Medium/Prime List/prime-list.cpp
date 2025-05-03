//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
  bool isprime(int n)
  {
      if(n==0 || n==1) return 0;
      
      for(int i=2;i*i<=n;i++)
      {
          if(n%i==0) return 0;
      }
      return 1;
  }
  int solve(int n)
  {
     int i=n,j=n;
     bool isfound=0;
     int ans=0;
     while(!isfound)
     {
       bool l=isprime(i);
       bool r=isprime(j);
       
       if(l && r)
       {
          ans=min(i,j);
          isfound=1;
       }
       else if(l)
       { 
           ans=i;
           isfound=1;
       }
       else if(r)
       { 
           ans=j;
           isfound=1;
       }
       
       i--;
       j++;
       if(i<=0)
       i=1;
     }
     return ans;
  }
    Node *primeList(Node *head) {
        // code here
        Node*t=head;
        
        while(t)
        {
            t->val=solve(t->val);
            t=t->next;
        }
        
        return head;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends