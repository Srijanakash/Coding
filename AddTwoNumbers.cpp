/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *res=NULL,*temp=NULL,*prev=NULL;
        int sum,carry=0;
        while(l1 || l2)
        {
            sum=carry+(l1?l1->val:0)+(l2?l2->val:0);
            carry=(sum>=10?1:0);
            sum%=10;
            temp=new ListNode(sum);
            if(res==NULL)
                res=temp;
            else
                prev->next=temp;
            prev=temp;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        if(carry>0)
            temp->next=new ListNode(carry);
        return res;
    }
};
