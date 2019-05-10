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
    
    void dfs(TreeNode *root, string x, int& sum)
    {
        if(!root)
            return ;
        
        if(root->val==1)
            x+='1';
        else 
            x+='0';
        
        if(root->left==NULL && root->right==NULL)
        {
            int k=0;
            for(int i=x.size()-1; i >= 0; i--)
            {
                sum += pow(2,k) * (x[i]-'0');
                k++;
            }
        }
        
        dfs(root->left, x, sum);
        dfs(root->right, x, sum);
    }
    
    int sumRootToLeaf(TreeNode* root) 
    {
        
        string x = "";
        int sum = 0;
        
        dfs(root, x, sum);
    
        return sum;
    }
};
