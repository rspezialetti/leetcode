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
    
    ListNode* rotateStep(ListNode* head)
    {
        
        ListNode* it = head;
        
        ListNode* new_first = new ListNode(0);
        new_first->next = head;
        
        ListNode* prev = NULL;
        
        while(it)
        {
            if(it->next == NULL)
            {
                new_first->val = it->val;
                prev->next = NULL;
                
                break;
            }   
            
            prev = it;
            it = it->next;
        }
        
        return new_first;
        
    }
    
    /*Slow but working*/
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head)
            return head;
        
        while(k && head->next)
        {
            head = rotateStep(head);    
            --k;
        }
        
        return head;
    }
    
     ListNode* rotateRight(ListNode* head, int k) 
     {
        if(!head || !head->next) return head;

        int len = 0;
        ListNode* it = head;
         
        while(it)
        {
            it = it->next; 
            len++;
        } 
         
        /*Is multiple avoid to rotate*/
        k = k % len;
        
         if(k == 0) 
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
         
        while(k > 0)
        {
            fast = fast->next; 
            k--;    
        } 
         
        while(fast->next)
        {
            fast = fast->next; 
            slow = slow->next;
        } 
        
        ListNode* res = slow->next;
        
        slow->next = NULL;
        fast->next = head;
        
        return res;
    }
};
