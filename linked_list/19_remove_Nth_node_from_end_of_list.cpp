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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        for(int k = 0; k < n; ++k)
        {
            p2 = p2->next;
            if(!p2)
                return head->next;
        }
        
        while(p2)
        {
            p2 = p2->next;
            
            if(p2 == nullptr)
            {
                p1->next = p1->next->next;
                break;
            }
            else
            {
                p1 = p1->next;
            }
        }
        return head;
    }
};
