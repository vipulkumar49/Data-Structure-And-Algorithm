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
    TreeNode* buildBinaryTree(vector<int> &preorder, vector<int> &inorder, int ps, int pe, int is, int ie, unordered_map<int, int> &inorder_index) {
        if(is > ie) return NULL;
        
        int root_value = preorder[ps];
        TreeNode* root = new TreeNode(root_value);
        // get the pos of root
        int pos = inorder_index[root_value];
        // recursive call on left and right subtree
        root->left = buildBinaryTree(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1, inorder_index); 
        root->right = buildBinaryTree(preorder, inorder, ps + pos - is + 1, pe, pos + 1, ie, inorder_index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size(); // size of array 
        unordered_map<int, int> inorder_index;
        for(int i = 0; i < n; i++) {
            inorder_index[inorder[i]] = i;
        }
        return buildBinaryTree(preorder, inorder, 0, n - 1, 0, n - 1, inorder_index);
    }
};