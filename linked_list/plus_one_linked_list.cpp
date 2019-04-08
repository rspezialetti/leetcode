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
    
    int sumNode(ListNode* node)
    {
        const int sum = node->val + 1;
        node->val = sum % 10;
        
        return sum > 9;
    }
    
    ListNode* plusOne(ListNode* head) {
     
        if(head->next == NULL)
        {
            const int carry = sumNode(head);
            
            if(carry)
            {
                ListNode* node = new ListNode(1);
                node->next = head;
                        
                return node;
            }
            else
            {
                return head;
            }
        }
        
        ListNode* it = head;
        vector<ListNode*> nodes;
        
        while(it)
        {   
            if(it->next == NULL)
            {
                int carry = sumNode(it);
                
                while(carry)
                {
                    auto n = nodes.back();
                    carry = sumNode(n);
                    
                    if(n == head && carry)
                    {
                        ListNode* node = new ListNode(1);
                        node->next = head;
                        
                        return node;
                    }
                    
                    nodes.pop_back();
                }
            }
            
            nodes.push_back(it);
            it = (*it).next;
        }
        
        return head;
    }

    int sumNode(ListNode* node, ListNode* parent)
    {
        if(node == NULL)
        {
            const int sum = parent->val + 1;
            parent->val = sum % 10;
        
            return sum > 9;    
        }
        
        /*Recursive*/
        const int carry = sumNode(node->next, node);
        if(parent == NULL) return carry;
        
        /*Sum Carry*/
        const int sum = parent->val + carry;
        parent->val = sum % 10;
        
        return sum > 9; 
    }
    
    ListNode* plusOne(ListNode* head) 
    {
        const int carry = sumNode(head, NULL);
        
        if(carry == 0)
            return head;
        
        ListNode* node = new ListNode(1);
        node->next = head;
            
        return node;   
    }
};
