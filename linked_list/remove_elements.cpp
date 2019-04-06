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
    /* Complexity Analysis Time complexity : O(n) Space complexity : O(1) */		
    ListNode* removeElements(ListNode* head, int val) 
    {
        
        ListNode temp(-1);
        temp.next = head;
        
        ListNode* it = &temp;
        
        while(it->next)
        {
            if(it->next->val == val)
                it->next = it->next->next;
            else
                it = it->next;    
        }
        
        return temp.next;
    }
    
};
