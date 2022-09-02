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
    vector<double> averageOfLevels(TreeNode* root) {
        vector <double> ans;
        queue<TreeNode *> q;
        q.push(root);
        
        while (! q.empty())
        {
            int n = q.size();
            double sum = 0;
            
            for (int i = 0; i < n; i++)
            {
                TreeNode *root = q.front();
                if (root->left)
                {
                    q.push(root->left);
                }
                if (root->right)
                {
                    q.push(root->right);
                }
                sum += root->val;
                q.pop();
            }
            ans.push_back(sum/ n);
        }
        
        
        
        return ans;
    }
};