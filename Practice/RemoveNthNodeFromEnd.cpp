/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *temp1=dummy,*temp2=dummy;
        int count=0;
        for(int i=1;i<=n+1;i++)
            temp1=temp1->next;
        while(temp1!=NULL)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp2->next=temp2->next->next;
        return dummy->next;
    }
};
