/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool isValidBST(TreeNode* root) 
    {
        return dfs_valid(root, LONG_MIN, LONG_MAX);
    }

    bool dfs_valid(TreeNode *root, long low, long high) 
    {
        if (!root) 
            return true;
        
        return low < root->val 
            && root->val < high 
            && dfs_valid(root->left, low, root->val)
            && dfs_valid(root->right, root->val, high);
    }  

};
