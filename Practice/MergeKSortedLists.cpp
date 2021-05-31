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
class Solution 
{
    void push(ListNode **head,int val)
    {
        ListNode *newNode= new ListNode(val);
        newNode->next=*head;
        *head=newNode;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<int>q;
        int n=lists.size();
        if(n==0)
            return NULL;
        for(int i=0;i<n;i++)
        {
            ListNode *temp=lists[i];
            while(temp)
            {
                q.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode *res=NULL,*head=NULL;
        while(!q.empty())
        {
            push(&head,q.top());
            q.pop();
        }
        return head;
    }
};
