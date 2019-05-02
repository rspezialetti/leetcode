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
    int maxDepth(TreeNode* root) 
    {
        
        if(root == NULL)
            return 0;
        
        const int val_l = maxDepth(root->left);
        const int val_r = maxDepth(root->right);
        
        return max(val_l, val_r) + 1;
    }
};
