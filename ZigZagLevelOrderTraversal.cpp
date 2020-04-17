/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>result;
        if(root==NULL)
            return result;
        stack<TreeNode *>s1,s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty())
        {
            TreeNode *curr;
            vector<int>temp;
            while(!s1.empty())
            {
                curr=s1.top();
                temp.push_back(curr->val);
                s1.pop();
                if(curr->left)
                    s2.push(curr->left);
                if(curr->right)
                    s2.push(curr->right);
            }
            if(!temp.empty())
                result.push_back(temp);
            temp.clear();
            while(!s2.empty())
            {
                curr=s2.top();
                temp.push_back(curr->val);
                s2.pop();
                if(curr->right)
                    s1.push(curr->right);
                if(curr->left)
                    s1.push(curr->left);
            }
            if(!temp.empty())
                result.push_back(temp);
        }
        return result;
    }
};
