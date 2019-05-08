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
    
    int dfs(TreeNode* root, int& res)
    {
        if(root == nullptr)
            return 0;
        
        const int left = dfs(root->left, res);
        const int right = dfs(root->right, res);
        
        res += abs(left) + abs(right);
        
        return root->val + left + right - 1;
    }
    
    int distributeCoins(TreeNode* root) 
    {
        int res = 0;
        dfs(root, res);
        
        return res;
    }
};
