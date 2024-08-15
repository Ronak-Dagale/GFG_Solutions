//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node* reverse(Node*h)
  {
      Node*prev=NULL,*curr=h,*ne;
      while(curr)
      {
          ne=curr->next;
          curr->next=prev;
          prev=curr;
          curr=ne;
      }

      return prev;
  }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node*temp=reverse(head);
        int c=1;
        Node*ans=new Node(-1);
        Node*anstail=ans;
        
        while(temp)
        {
            int s=temp->data+c;
            temp->data=s%10;
            c=s/10;
            
            anstail->next=temp;
            anstail=temp;
            
            temp=temp->next;
        }
        if(c)
        {
            Node*nn=new Node(c);
            anstail->next=nn;
            anstail=nn;
        }
        
        ans->next=reverse(ans->next);
        return ans->next;
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
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends