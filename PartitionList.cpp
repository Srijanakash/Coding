/*
Given a linked list and a value x, partition it such that 
all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *beforeHead=new ListNode(0);
        ListNode *afterHead=new ListNode(0);
        ListNode *before=beforeHead,*after=afterHead;
        while(head)
        {
            if(head->val<x)
            {
                before->next=head;
                before=before->next;
            }
            else
            {
                after->next=head;
                after=after->next;
            }
            head=head->next;
        }
        after->next=NULL;
        before->next=afterHead->next;
        return beforeHead->next;
    }
};
