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
    
    void insert(TreeNode *t, int val)
    {
        if (val > t->val)
        {
            if (t->right)
            {
                insert(t->right, val);
            }
            else
            {
                t->right = new TreeNode(val);
            }
        }
        else
        {
            if (t->left)
            {
                insert(t->left, val);
            }
            else
            {
                t->left = new TreeNode(val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
        {
            return new TreeNode(val);
        }
        insert(root, val);
        return root;
    }
};