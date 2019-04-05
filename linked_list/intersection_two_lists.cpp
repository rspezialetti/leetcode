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

    /* Complexity Analysis Time complexity : O(mn) Space complexity : O(1) */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        for(ListNode* it_a = headA; it_a != NULL; it_a = it_a->next)
        {
            for(ListNode* it_b = headB; it_b != NULL; it_b = it_b->next)
            {
                if(it_a == it_b)
                    return it_a;
            }
        }

        return NULL;
    }

    /* Complexity Analysis Time complexity : O(m+n) Space complexity : O(m) or (n) */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* result = NULL;
        unordered_map<ListNode*, int> map;
        int count = 0;

        for(ListNode* it_a = headA; it_a != NULL; it_a = it_a->next)
        {

            map.emplace(it_a, count);
            ++count;
        }

        for(ListNode* it_b = headB; it_b != NULL; it_b = it_b->next)
        {
            if(map.find(it_b) != map.end())
                return it_b;
        }

        return result;
    }

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
