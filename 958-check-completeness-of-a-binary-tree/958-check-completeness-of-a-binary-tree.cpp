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
    bool isCompleteTree(TreeNode* root) {
        int i;
        queue<pair<TreeNode*, int>> q;
        vector<int> v;
        
        q.push({root, 1});
        
        while (q.size() != 0)
        {
            int s = q.size();
            for (i = 0; i < s; i++)
            {
                pair <TreeNode*, int> p = q.front();
                q.pop();
                TreeNode* t = p.first;
                int index = p.second;
                
                v.push_back(index);
                if (v.size() > 1 && v[v.size() - 1] != v[v.size() - 2] + 1)
                    return false;
                
                if (t->left)
                {
                    q.push({t->left, index*2});
                }
                if (t->right)
                {
                    q.push({t->right, index*2 + 1});
                }
            }
        }
        return true;
    }
};