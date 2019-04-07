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
    ListNode* deleteDuplicates(ListNode* head)
    {

        if(!head || !head->next)
            return head;

        ListNode* it = head;

        ListNode dummy(0);
        ListNode* it_res = &dummy;

        unordered_map<int, ListNode*> mapping;

        while(it)
        {
            if(mapping.find(it->val) == mapping.end())
            {
                it_res->next = it;
                it_res = it_res->next;

                mapping.emplace(it->val, it);
            }

            it = it->next;
        }

        it_res->next = nullptr;
        return dummy.next;
    }

    /*Time complexity : O(n), Space complexity : O(1) */
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* it = head;

        while(it && it->next)
        {
            if((*it).val == (*(*it).next).val)
            {
                (*it).next = (*(*it).next).next;
            }
            else
                it = (*it).next;
        }

        return head;
    }


};
