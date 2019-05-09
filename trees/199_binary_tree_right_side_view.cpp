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
    
    
    void traverse(TreeNode* root, vector<int>& nums, int depth)
    {
        if(!root)
            return;
        
        if(nums.size() == depth)        
            nums.push_back(root->val);
        
        traverse(root->right, nums, depth+1);
        traverse(root->left, nums, depth+1);
    }
    
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> nums;
        traverse(root, nums, 0);
        
        return nums;
    }
};
