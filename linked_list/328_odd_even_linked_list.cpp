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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        
        int count = 1;
        
        ListNode* list_odd_start = nullptr;
        ListNode* list_odd_end = nullptr;
        
        ListNode* list_even_start = nullptr;
        ListNode* list_even_end = nullptr;
        
        while(head)
        {
            if(count % 2)
            {
                if(!list_odd_start)
                {
                    list_odd_start = head;
                    list_odd_end = list_odd_start;
                }
                else
                {
                    (*list_odd_end).next = head;
                    list_odd_end = head;
                }
            }
            else
            {
                if(!list_even_start)
                {
                    list_even_start = head;
                    list_even_end = list_even_start;
                }
                else
                {
                    (*list_even_end).next = head;
                    list_even_end = head;
                }                
            }
               
            head = head->next;
            ++count;
        }
        
        list_even_end->next = nullptr;
        
        list_odd_end->next = list_even_start;
        return list_odd_start;
    }
};
