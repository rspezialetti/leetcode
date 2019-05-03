class Solution {
public:
   
    int surfaceArea(vector<vector<int>>& grid) 
    {
       int res = 0;
        
       for (int i = 0;i < grid.size(); i++)
       {
            for (int j = 0;j < grid[0].size();j++)
            {
				//if there is a non zero stack, add top and bottom area
                if (grid[i][j] != 0)
                    res += 2;
                
				//compute upmost stacks
                if (i == 0)
                    res += grid[i][j];
                
				//compute leftmost stacks
                if (j == 0)
                    res += grid[i][j];
                
				//compute bottom stacks
                if (i == grid.size() - 1)
                    res += grid[i][j];
                
				//compute rightmost stacks
                if (j == grid[0].size() - 1)
                    res += grid[i][j];
                
				//next row 
                if (i < grid.size() - 1)
                    res += abs(grid[i][j] - grid[i + 1][j]);
                
				//next col
                if (j < grid[0].size() - 1)
                    res += abs(grid[i][j] - grid[i][j + 1]);
            }
        }
        return res;
    }
};
