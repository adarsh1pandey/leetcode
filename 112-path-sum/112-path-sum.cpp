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
    bool valu = false;
    void dfs(TreeNode* &root, int target, int sum)
    {
        if (root == NULL)
        {
            return;
        }
        
        if (root->left == NULL && root->right == NULL)
        {
            sum += root->val;
            if (sum == target)
            {
                valu = true;
            }
            return;
        }
        if (valu)
            return;
        sum += root->val;
        dfs(root->left, target, sum);
        dfs(root->right, target, sum);
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;
        dfs(root, targetSum, 0);
        return valu;
    }
};