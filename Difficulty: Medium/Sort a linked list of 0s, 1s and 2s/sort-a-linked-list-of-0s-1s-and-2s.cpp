//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node*zero=new Node(-1);
        Node *one=new Node(-1);
        Node *two=new Node(-1);
        Node *zerotail=zero,*onetail=one,*twotail=two;
        
        Node*tmp=head;
        while(tmp)
        {
            if(tmp->data==0)
            {
                zerotail->next=tmp;
                zerotail=tmp;
            }
            else if(tmp->data==1)
            {
                onetail->next=tmp;
                onetail=tmp;
            }
            else
            {
                twotail->next=tmp;
                twotail=tmp;
            }
            tmp=tmp->next;
        }
        zerotail->next=NULL;
        onetail->next=NULL;
        twotail->next=NULL;
        
        Node *ans=new Node(-1);
        Node*anstail=ans;
        
        tmp=zero->next;
        while(tmp)
        {
            anstail->next=tmp;
            anstail=tmp;
            tmp=tmp->next;
        }
         tmp=one->next;
        while(tmp)
        {
            anstail->next=tmp;
            anstail=tmp;
            tmp=tmp->next;
        }
         tmp=two->next;
        while(tmp)
        {
            anstail->next=tmp;
            anstail=tmp;
            tmp=tmp->next;
        }
        
       return ans->next;
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends