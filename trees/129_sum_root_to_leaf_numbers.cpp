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
    
    int sumNumbers(TreeNode* root) {
        
        int res = 0, one = 0;
        
        if(!root)
            return 0;
        
        traverse(root, res, one);
        return res;
    }
    
    void traverse(TreeNode* node, int& res, int& one) 
    {
        if(node && !node->left && !node->right) 
        {
            one = one * 10 + node->val;
            res += one;
            
            return;
        }
    
        one = one * 10 + node->val;
        int tp0 = one, tp1 = one;
        
        if(node->left)
            traverse(node->left, res, tp0);
        
        if(node->right)
            traverse(node->right, res, tp1);
    }
};
