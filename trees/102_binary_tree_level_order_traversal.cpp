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
    
    void bfsTraversal(TreeNode* root, vector<vector<int>>& ints, unordered_map<int,int>& dephts)
    {
        if(!root)
            return;
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty())
        {
            const TreeNode* current = nodes.front();
            nodes.pop();
            
            const int idx_depth = dephts[(*current).val];
            ints[idx_depth].push_back(current->val);
            
            if(current->left)
                nodes.push(current->left);
            
            if(current->right)
                nodes.push(current->right);
        }
    }
    
    void getDepth(TreeNode* current, TreeNode* parent, unordered_map<int,int>& dephts, int& max_depth)
    {
        if(!current)
            return;
        
        if(parent != nullptr)
        {
            dephts[current->val] = dephts[parent->val] + 1;
            max_depth = max(max_depth, dephts[current->val]);
        }
        else
            dephts[current->val] = 0;
        
        getDepth(current->left, current, dephts, max_depth);
        getDepth(current->right, current, dephts, max_depth);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> values;
        
        if(!root)
            return  values;
            
        unordered_map<int,int> dephts;
        int max_depth = 0;
        
        getDepth(root, nullptr, dephts, max_depth);
        values.resize(max_depth + 1, vector<int>());
        
        bfsTraversal(root, values, dephts);
        
        return values;
    }

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> values;
        
        if(!root)
            return  values;
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty())
        {
            vector<int> v_level;
            const int size_queue = nodes.size();
            
            for(size_t i = 0; i < size_queue ; ++i)
            {
                const TreeNode* current = nodes.front(); 
                v_level.push_back(current->val);
                
                nodes.pop();
                
                if(current->left)
                    nodes.push(current->left);
            
                if(current->right)
                    nodes.push(current->right);
            }
            
            values.push_back(v_level);
        }
        
        return values;
    }
};
