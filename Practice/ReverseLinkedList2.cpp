/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        ListNode *curr=head,*prev=NULL;
        while(m>1)
        {
            prev=curr;
            curr=curr->next;
            m--;
            n--;
        }
        ListNode *connect=prev,*tail=curr;
        ListNode *third=NULL;
        while(n>0)
        {
            third=curr->next;
            curr->next=prev;
            prev=curr;
            curr=third;
            n--;
        }
        if(connect)
            connect->next=prev;
        else
            head=prev;
        tail->next=curr;
        return head;
    }
};
