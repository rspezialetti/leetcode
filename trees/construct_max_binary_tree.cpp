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

    TreeNode* constructNodeMax(vector<int>& nums, int start, int end)
    {
        if(start == end)
            return nullptr;
        
        int idx_max = start;
        
        for(int i = start; i < end; ++i)
        {
            if(nums[i] > nums[idx_max])    
                idx_max = i;
        }
        
        TreeNode* node = new TreeNode(nums[idx_max]);
        
        node->left = constructNodeMax(nums, start, idx_max);
        node->right = constructNodeMax(nums, idx_max + 1, end);
        
        return node;
    }
    /*Time Complexity: O(n^2), Space Complexity: O(n)*/
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return constructNodeMax(nums, 0, nums.size());
    }
    
};
