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
    
    void getLeaves(TreeNode* root1, vector<int>& leaves)
    {
        if(root1 == NULL)
            return;
        
        if(root1->left == NULL && root1->right == NULL)
            leaves.push_back(root1->val);
        
        getLeaves(root1->left, leaves);
        getLeaves(root1->right, leaves);
    }
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {   
       
        vector<int> v_leaves_1;
        vector<int> v_leaves_2;
        
        getLeaves(root1, v_leaves_1);
        getLeaves(root2, v_leaves_2);
        
         if(v_leaves_1.size() != v_leaves_2.size())
            return false;
        
        for(size_t i = 0; i < v_leaves_1.size(); ++i)
        {
            if(v_leaves_1[i] != v_leaves_2[i])
                return false;
        }
        
        return true;
    }
};
