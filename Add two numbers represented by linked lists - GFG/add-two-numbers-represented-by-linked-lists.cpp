// { Driver Code Starts
// driver

#include <bits/stdc++.h>
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
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

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
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
    struct Node* addTwoLists(struct Node* first, struct Node* second) {
        if(second == NULL) return first;
        if(first == NULL) return second;
        Node* list1 = reverse(first);
        Node* list2 = reverse(second);
        // cout << list1->data << " " << list2->data << "\n";
        Node* head = NULL, *tail = NULL;
        int carry = 0;
        while(list1 != NULL && list2 != NULL) {
            int data = list1->data + list2->data + carry;
            carry = data / 10;
            Node* newNode = new Node(data % 10);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = tail->next;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        while(list1 != NULL) {
            int data = list1->data + carry;
            carry = data / 10;
            Node* newNode = new Node(data % 10);
            tail->next = newNode;
            tail = tail->next;
            list1 = list1->next;
        }
        while(list2 != NULL) {
            int data = list2->data + carry;
            carry = data / 10;
            Node* newNode = new Node(data % 10);
            tail->next = newNode;
            tail = tail->next;
            list2 = list2->next;
        }
        if(carry != 0) {
            Node* newNode = new Node(carry);
            tail->next = newNode;
            tail = tail->next;
        }
        tail->next = NULL;
        head = reverse(head);
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
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends