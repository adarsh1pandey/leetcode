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
    bool ans = false;
    
    void dfs(TreeNode* root, int targetSum, int sum)
    {
        if (!root)
            return;
        
        if(root->left == NULL && root->right == NULL)
        {
            sum += root->val;
            if (sum == targetSum)
            {
                ans = true;
            }
            return;   
        }
        if (ans)
        {
             return;
        }
        sum += root->val;
        dfs(root->left, targetSum, sum);
        dfs(root->right, targetSum, sum);
    }
    
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
        {
            return false;
        }
        dfs(root, targetSum, 0);
        return ans;
    }
};