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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* head = NULL, *tail = NULL;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        vector<int> res;
        for(int i = 0; i < k; i++) {
            if(lists[i] != NULL)
                pq.push({lists[i]->val, lists[i]});
        }
        while(!pq.empty()) {
            int data = pq.top().first;
            ListNode* node = pq.top().second;
            ListNode* newNode = new ListNode(data);
            pq.pop();
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = tail->next;
            }
            if(node->next != NULL) {
                pq.push({node->next->val, node->next});
            }
        }
        if(head == NULL) return head;
        tail->next = NULL;
        return head;
    }
};