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
    
    void postOrder(TreeNode* root, vector<int>& values)
    {
        if(root == nullptr)
            return;
        
        postOrder(root->left, values);
        postOrder(root->right, values);
        
        values.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) 
    {
        
        vector<int> values;
        postOrder(root, values);
        
        return values;
    }
};
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
    
    void traversal(TreeNode* root, vector<int>& values)
    {
        stack<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty())
        {
            auto node = nodes.top();
            nodes.pop();
            
            values.push_back(node->val);
            
            if(node->left)
                nodes.push(node->left);
            
            if(node->right)
                nodes.push(node->right);
        }
    }
    
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(root == nullptr)
            return vector<int>();
        
        vector<int> values;
        traversal(root, values);
        
        reverse(values.begin(), values.end());
        
        return values;
    }
};
