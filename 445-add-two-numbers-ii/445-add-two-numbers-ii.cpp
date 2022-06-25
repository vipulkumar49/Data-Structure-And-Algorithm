/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL, *curr = head, *next = head;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* r1 = reverse(l1);
        ListNode* r2 = reverse(l2);
        int carry = 0;
        ListNode* head = NULL, *tail = NULL;
        while(r1 != NULL && r2 != NULL) {
            int data = r1->val + r2->val + carry;
            carry = data / 10;
            ListNode* newNode = new ListNode(data % 10);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = tail->next;
            }
            r1 = r1->next;
            r2 = r2->next;
        }
        while(r1 != NULL) {
            int data = r1->val + carry;
            carry = data / 10;
            ListNode* newNode = new ListNode(data % 10);
            tail->next = newNode;
            tail = tail->next;
            r1 = r1->next;
        }
        while(r2 != NULL) {
            int data = r2->val + carry;
            carry = data / 10;
            ListNode* newNode = new ListNode(data % 10);
            tail->next = newNode;
            tail = tail->next;
            r2 = r2->next;
        }
        if(carry != 0) {
            ListNode* newNode = new ListNode(carry);
            tail->next = newNode;
            tail = tail->next;
        }
        tail->next = NULL;
        ListNode* res = reverse(head);
        return res;
    }
};