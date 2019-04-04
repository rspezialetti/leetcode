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

    /* Complexity Analysis Time complexity : O(m+n) Space complexity : O(1) */	
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        
        if (p1 == NULL || p2 == NULL) return NULL;

        while (p1 != NULL && p2 != NULL && p1 != p2) 
        {
            p1 = p1->next;
            p2 = p2->next;

            if (p1 == p2) return p1;

            if (p1 == NULL) p1 = headB;
            if (p2 == NULL) p2 = headA;
        }
        
        return p1;
        
    }
};
