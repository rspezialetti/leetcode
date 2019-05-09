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
    
    bool isCompleteTree(TreeNode* root) 
    {
        if(!root)
            return false;
        
        bool res = true;
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty())
        {
            TreeNode* current = nodes.front();
            nodes.pop();
            
            if(current->left && current->right || current->left)
            {
                res = true;
                nodes.push(current->left);
                
                if(current->right)
                    nodes.push(current->right);
            }
            else if(!(!current->left && !current->right))
                res = false;
            
            if(!res)
                break;
        }
        
        return res;
    }
};
