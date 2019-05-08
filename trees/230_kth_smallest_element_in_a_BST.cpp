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
    
    void inOrder(TreeNode* root, vector<int>& values, int k)
    {
        if(values.size() == k || !root)
            return;
        
        inOrder(root->left, values, k);
        values.push_back(root->val);
        inOrder(root->right, values, k);
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        
        if(!root)
            return 0;
        
        vector<int> values;
        inOrder(root, values, k);
        
        return values.size() < k ? 0 : values[k-1];
    }
};
