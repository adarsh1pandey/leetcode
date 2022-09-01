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
    int goodNodes(TreeNode* root) {
        int count = 0;
        if (root == NULL) return 0;
        helper(root, count, root->val);
        
        return count;
    }
    void helper(TreeNode* root, int &count, int maxele)
    {
        if (root == NULL)
            return;
        if (root->val >= maxele)
        {
            count++;
            maxele = root->val;
        }
        helper(root->left, count, maxele);
        helper(root->right, count, maxele);
            
    }
};