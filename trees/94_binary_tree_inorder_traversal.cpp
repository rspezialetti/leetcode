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
    
    void inorder(TreeNode* root, vector<int>& values)
    {
        if(!root)
            return;
        
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> values;
        inorder(root, values);
        
        return values;
    }

// iterate, use stack
vector<int> inorderTraversal(TreeNode* root) {
    
    vector<int> v;
    if(!root) 
        return v;
    
    TreeNode* temp = root;
    stack<TreeNode*> s;
    
    while(temp || !s.empty())
    {
        while(temp)
        {
            s.push(temp);
            temp = temp->left;
        }
        
        temp = s.top();
        s.pop();
        
        v.push_back(temp->val);
        temp = temp->right;
    }
    return v;
}
    int countNodes(TreeNode* root, int k, int& val)
    {
        if(!root)
            return 0;
        
        const int left = countNodes(root->left, k, val) + 1;
        const int right = countNodes(root->right, k - left, val) + 1;
        
        if(left == k)
            val = root->val;
        
        return left + right - 1;
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        
        if(!root)
            return 0;
        
        int val = 0;
        countNodes(root, k, val);
        
        return val;
    }
};
