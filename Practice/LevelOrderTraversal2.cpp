/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution 
{
public:
     vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>>result;
        if(root==NULL)
            return result;
        queue<TreeNode *>q;
        q.push(root);
        int nodeCount=0;
        while(q.empty()==false)
        {
            nodeCount=q.size();
            vector<int>t;
            while(nodeCount>0)
            {
                TreeNode *temp=q.front();
                //cout<<temp->data<<" ";
                t.push_back(temp->val);
                q.pop();
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                nodeCount--;
            }
            result.push_back(t);
        }
         reverse(result.begin(),result.end());
        return result;
    }
};
