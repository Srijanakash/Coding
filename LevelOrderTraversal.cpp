/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>result;
        if(!root)
            return result;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>temp;
            int nodeCount=q.size();
            while(nodeCount>0)
            {
                nodeCount--;
                TreeNode *curr=q.front();
                q.pop();
                if(curr)
                    temp.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            result.push_back(temp);
        }
        return result;
    }
};
