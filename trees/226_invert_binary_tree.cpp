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
    TreeNode* invertTree(TreeNode* root) 
    {
        
        if(root == nullptr)
            return root;
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty())
        {
            TreeNode* current = nodes.front();
            nodes.pop();
            
            TreeNode* temp = current->left;
                
            current->left = current->right;
            current->right = temp;
            
            if(current->right)
                nodes.push(current->right);
            
            if(current->left)
                nodes.push(current->left);
        }
        return root;
    }

    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)
            return root;
        
        TreeNode* right = invertTree(root->right);
        TreeNode* left = invertTree(root->left);
        
        root->left = right;
        root->right = left;
        
        return root;
    }
};
