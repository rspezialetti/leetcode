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
    /*Time Complexity:O(n), Space Complexity:O(h) h=height of tree*/
    bool isUnivalTree(TreeNode* root) 
    {
        
        if(root == NULL)
            return true;
        
        if(root->left != NULL)
            if(root->val != root->left->val)
                return false;
        
        if(root->right != NULL)
            if(root->val != root->right->val)
                return false;
       
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
