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
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(TreeNode* root, int targetSum, int sum)
    {
        if (root == NULL)
            return;
        sum += root->val;
        path.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == targetSum)
            {
                ans.push_back(path);
            }
        }
        dfs(root->left, targetSum, sum);
        dfs(root->right, targetSum, sum);
        path.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        int sum = 0;
        dfs(root, targetSum, sum);
        return ans;
        
        
    }
};