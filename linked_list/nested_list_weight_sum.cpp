/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    
    int sum = 0;
    int depth = 1;
    
    int depthSum(vector<NestedInteger>& nestedList)
    {        
        for(size_t l = 0; l < nestedList.size(); ++l)
        {
            auto node = nestedList[l];
            
            if(node.isInteger())            
                sum += depth * nestedList[l].getInteger();
            else
            {
                auto list = node.getList();
                if(list.size())
                {
                    depth += 1;
                    sum = depthSum(list);    
                }
                
            }
            
            if(l == nestedList.size() - 1)
                depth -= 1;
        }
    
        return sum;
    }
};
