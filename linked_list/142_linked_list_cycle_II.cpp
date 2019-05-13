/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        set<ListNode*> nodes;
        
        ListNode* res = nullptr;
        ListNode* temp = head;
        
        while(temp)
        {
            if(nodes.count(temp) == 1)
                return temp;
            
            nodes.insert(temp);
            temp = (*temp).next;
        }
        
        return res;
    }
};
