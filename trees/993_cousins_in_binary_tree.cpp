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
    
    void dfs(TreeNode* parent, TreeNode* current, unordered_map<int, TreeNode*>& parents, unordered_map<int, int>& dephts)
    {
        if(!current)
            return;
        
        if(parent != nullptr)
            dephts[(*current).val] = dephts[(*parent).val] + 1;
        else
            dephts[(*current).val] = 0;
            
        parents[(*current).val] = parent;
        
        dfs(current, current->left, parents, dephts);
        dfs(current, current->right, parents, dephts);
    }
    
    bool isCousins(TreeNode* root, int x, int y) 
    {
        unordered_map<int, TreeNode*> parents;
        unordered_map<int, int> dephts;
            
        dfs(nullptr, root, parents, dephts);
        
        return (dephts[x] == dephts[y]) && (parents[x] != parents[y]);
    }
};
