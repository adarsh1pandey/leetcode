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
    TreeNode* searchBST(TreeNode* root, int val) {
        
       TreeNode *t = root;
        while (t) 
        {
            if (t->val == val)
            {
                return t;
            }
            else if (t->val < val)
            {
                t = t->right;
            }
            else 
            {
                t = t->left;
            }
        }
        return NULL;
    }
};