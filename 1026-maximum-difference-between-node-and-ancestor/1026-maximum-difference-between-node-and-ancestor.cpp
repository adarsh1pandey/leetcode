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
    int find(TreeNode* root, int maxNum, int minNum){
        if (root == NULL){
            return maxNum - minNum;
        }
            
        maxNum = max(maxNum, root->val);
        minNum = min(minNum, root->val);
        
        return max(find(root->left, maxNum, minNum), find(root->right, maxNum, minNum));
    
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxNum = 0;
        int minNum = 1e5;
        return find(root, maxNum, minNum);
    }
};