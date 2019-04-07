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

    int nextLargerNode(ListNode* head)
    {
        int larger_node = 0;

        if(head->next == nullptr)
            return larger_node;

        ListNode * it = head;
        const int val_curr = it->val;

        while(it)
        {
            if(it->val > val_curr)
            {
                larger_node = it->val;
                break;
            }

            it = it->next;
        }

        return larger_node;

    }

    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> result;

        ListNode * it = head;
        while(it)
        {
            result.push_back(nextLargerNode(it));
            it = it->next;
        }

        return result;
    }

    /*Time Complexity O(n); Space Complexity o(n)*/
    vector<int> nextLargerNodes(ListNode* head)
    {
         vector<int> res, stack;

         for (ListNode* node = head; node; node = node->next)
         {
             while (stack.size() && res[stack.back()] < node->val)
             {
                 res[stack.back()] = node->val;
                 stack.pop_back();
             }

             stack.push_back(res.size());
             res.push_back(node->val);
         }

         for (int i: stack) res[i] = 0;
         return res;
     }
};
