/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
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
    bool isLeaf(TreeNode* root)
    {
        if(!root)
            return false;
        if(!root->left && !root->right)
            return true;
        return false;
    }
public:
    int minDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        int level=INT_MAX,l=0;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            l+=1;
            int nodeCount=q.size();
            while(nodeCount>0)
            {
                nodeCount--;
                TreeNode *temp=q.front();
                q.pop();
                if(isLeaf(temp))
                    return l;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return l;
    }
};
