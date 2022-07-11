/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        Node *prev = NULL, *curr = root;
        while(curr->left) {
            Node* prev = curr;
            while(prev) {
                prev->left->next = prev->right;
                if(prev->next) prev->right->next = prev->next->left;
                prev = prev->next;
            }
            curr = curr->left;
        }
        return root;
    }
};