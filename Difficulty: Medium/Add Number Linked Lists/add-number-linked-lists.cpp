//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node* reversenode(Node*curr)
  {
     Node*prev=NULL,*ne=NULL;
     
     while(curr)
     {
         ne=curr->next;
         curr->next=prev;
         prev=curr;
         curr=ne;
     }
     return prev;
  }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        Node*ans=new Node(-1);
        Node*anstail=ans;
        
        num1=reversenode(num1);
        num2=reversenode(num2);
        
        int c=0;
        while(num1 || num2)
        {
            if(num1 && num2)
            {
                int z=num1->data+num2->data+c;
                Node*newnode=new Node(z%10);
                c=z/10;
                
                anstail->next=newnode;
                anstail=newnode;
                
                num1=num1->next;
                num2=num2->next;
            }
            else if(num1)
            {
                int z=num1->data+c;
                Node*newnode=new Node(z%10);
                c=z/10;
                
                 anstail->next=newnode;
                anstail=newnode;
                
                num1=num1->next;
            }
            else if(num2)
            {
                int z=num2->data+c;
                Node*newnode=new Node(z%10);
                c=z/10;
                
                anstail->next=newnode;
                anstail=newnode;
                
                num2=num2->next;
            }
        }
        
        if(c!=0)
        {
            Node*newnode=new Node(c);
            anstail->next=newnode;
            anstail=newnode;
        }
        
        Node*res=reversenode(ans->next);
        
        while(res && res->data==0) res=res->next;
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends