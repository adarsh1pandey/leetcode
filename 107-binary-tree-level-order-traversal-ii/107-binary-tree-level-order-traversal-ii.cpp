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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (q.size() != 0)
        {
            TreeNode *p = q.front();
            q.pop();
            
            if (p == NULL)
            {
                ans.push_back(level);
                level.clear();
                if (q.size() != 0)
                {
                    q.push(NULL);
                }
            }
            else
            {
                level.push_back(p->val);
                if(p->left)
                {
                    q.push(p->left);
                }
                if (p->right)
                {
                    q.push(p->right);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};