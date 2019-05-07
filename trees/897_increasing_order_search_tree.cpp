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
    
void traverseInOrder(TreeNode* root, vector<int>& values) 
{ 
    if (root == nullptr)
        return;
        
    traverseInOrder(root->left, values);   
    values.push_back(root->val);
    traverseInOrder(root->right, values); 
}  
    
TreeNode* increasingBST(TreeNode* root) 
{
    vector<int> values;
    traverseInOrder(root, values);
    
    TreeNode* new_root = new TreeNode(0);
    TreeNode* temp = new_root;
    
    for(size_t i = 0; i < values.size(); ++i)
    {
        temp->right = new TreeNode(values[i]);
        temp = temp->right;
    }
    
    return new_root->right;
}
};
