class Solution {
private:
    int readValue(string &S, int &i) 
    {
    
        int val = 0;
        
        for (; i < S.size() && isdigit(S[i]); ++i)
            val = 10 * val + S[i] - '0';
        
        return val;
    }
    
    int readDash(string &S, int &i) 
    {
        int cnt = 0;
        for (; i < S.size() && S[i] == '-'; ++i)
            ++cnt;
        
        return cnt;
    }
    
public:
    TreeNode* recoverFromPreorder(string S) {
        int i = 0, N = S.size();
        const int val = readValue(S, i);
        
        TreeNode* root = new TreeNode(val);
        
        stack<TreeNode*> s;
        s.push(root);
        
        while (i < S.size()) 
        {
            const int dep = readDash(S, i);
            const int val = readValue(S, i);
        
            TreeNode* node = new TreeNode(val);
            
            while (dep < s.size()) 
                s.pop();
            
            auto p = s.top();
            
            if (p->left) 
                p->right = node;
            else 
                p->left = node;
            
            s.push(node);
        }
        return root;
    }
};
