/*
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(!head || !head->next) 
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* nextnode = head -> next;
        ListNode* curr = head;
        ListNode* prev = &dummy;
        ListNode* temp;
        while(nextnode)
        {
            temp = nextnode;
            prev -> next = temp;
            curr -> next = nextnode->next;
            nextnode = nextnode -> next;
            temp -> next = curr;
            if(nextnode)
            {
                prev = curr;
                curr = nextnode;
                nextnode = nextnode -> next;
            }
        }
        return dummy.next;

    }
};
