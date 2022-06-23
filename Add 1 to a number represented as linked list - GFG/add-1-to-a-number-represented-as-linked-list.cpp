// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

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

class Solution
{
    public:
    Node* reverse(Node* head) {
        Node* prev = NULL, *curr = head, *next = head;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* addOne(Node *head) {
        if(head == NULL) return head;
        // cout << head->data << "\n";
        Node* reverseHead = reverse(head);
        // cout << reverseHead->data << "\n";
        Node* node = reverseHead;
        Node* prev;
        int carry = 1;
        while(node != NULL) {
            node->data = node->data + carry;
            carry = node->data / 10;
            node->data = (node->data) % 10;
            prev = node;
            node = node->next;
        }
        if(carry != 0) {
            Node* newNode = new Node(carry);
            prev->next = newNode;
        }
        head = reverse(reverseHead);
        return head;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends