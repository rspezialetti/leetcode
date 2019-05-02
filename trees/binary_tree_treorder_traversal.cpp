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
    
    void preorderVisit(TreeNode* root, vector<int>& values)
    {
        if(root==nullptr)
            return;
        
        values.push_back(root->val);
        
        preorderVisit(root->left, values);
        preorderVisit(root->right, values);
    }
    
    /*Recursive Solution*/
    vector<int> preorderTraversal(TreeNode* root) 
    {
        
        vector<int> result;
        preorderVisit(root, result);
        
        return result;
    }
    
    /*Iterative Solution*/
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        
        if(!root)
            return result;
        
        stack<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty())
        {
            root = nodes.top();
            
            result.push_back(root->val);
            nodes.pop();
            
            if(root->right)
                nodes.push(root->right);
            
            if(root->left)
                nodes.push(root->left);
        }
        
        return result;
    }
};
