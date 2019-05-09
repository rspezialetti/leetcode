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
    
    bool hasOne(TreeNode* root)
    {
        
        if(!root)
            return false;
        
        const bool has_one_left = pruneTree(root->left);
        const bool has_one_right = pruneTree(root->right);
        
        if(!has_one_left)
            root->left = nullptr;
        
        if(!has_one_right)
            root->right = nullptr;
        
        return root->val == 1 || has_one_left || has_one_right;
    }
    
    TreeNode* pruneTree(TreeNode* root) 
    {
        return hasOne(root) ? root :  nullptr;
    }
};
