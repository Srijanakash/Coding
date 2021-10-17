/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
    struct compare
    {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i=0;i<lists.size();i++)
            if(lists[i])
                pq.push(lists[i]);
        if(pq.empty())
            return NULL;
        ListNode *dummy = new ListNode(0);
        ListNode *last = dummy;
        while(!pq.empty())
        {
            ListNode* curr = pq.top();
            pq.pop();
            last->next = curr;
            last = last->next;

            if (curr->next != NULL)
                pq.push(curr->next);
        }
        return dummy->next;
    }
};
