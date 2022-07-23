/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* getBinaryTree(vector<int> preorder, vector<int> inorder, int preorder_start, int preorder_end, int inorder_start, int inorder_end) {
        if(inorder_start > inorder_end) return NULL;
        int root_value = preorder[preorder_start];
        TreeNode* root = new TreeNode(root_value);
        int pos = -1;
        for(int i = inorder_start; i <= inorder_end; i++) {
            if(inorder[i] == root_value) pos = i;
        }
        root->left = getBinaryTree(preorder, inorder, preorder_start + 1, preorder_start + pos - inorder_start, inorder_start, pos - 1); 
        root->right = getBinaryTree(preorder, inorder, preorder_start + pos - inorder_start + 1, preorder_end, pos + 1, inorder_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return getBinaryTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};