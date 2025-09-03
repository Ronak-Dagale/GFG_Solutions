/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node *pre=NULL,*curr=head,*ne=NULL;
        while(curr){
            ne=curr->next;
            curr->prev=ne;
            curr->next=pre;
            pre=curr;
            curr=ne;
        }
        return pre;
    }
};