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

    /* Complexity Analysis Time complexity : O(2n) Space complexity : O(n) */		
    bool isPalindrome(ListNode* head) {
        
          /*Reverse*/
        ListNode *reverse = NULL;
        ListNode *it = head;
        
        vector<int> values;
        
        while(it != NULL)
        {
            values.push_back(it->val);
            ListNode* next_it = (*it).next;
            (*it).next = reverse;
            
            reverse = it;
            it = next_it;
        }
        
        int count = 0; 
        int val = 0;
        
        while(reverse)
        {
            if(values[count] == reverse->val)
                val++;
            
            reverse = reverse->next;
            ++count;

        }

        return val == count;
	
	bool isPalindrome(ListNode* head) 
	{
		ListNode* fast = head;
	        ListNode* slow = head;
        
        	/*Put slow in median*/
	        while(fast && (*fast).next)
        	{
	            slow = (*slow).next;
        	    fast = (*(*fast).next).next;
	        }
        
        	ListNode* half_reverse = NULL;
        
        	while(slow)
	        {
        	    ListNode* slow_next = (*slow).next;
            
        	    (*slow).next = half_reverse;
        	    half_reverse = slow;
        	    
        	    slow = slow_next;
	        }
        
		bool result = true;
		while(half_reverse)
		{
			if((*half_reverse).val != (*head).val)
			return false;
            
			half_reverse = (*half_reverse).next;
			head = (*head).next;
		}
        
		return result;
	}
    }
};
