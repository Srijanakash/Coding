/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
Return the smallest level X such that the sum of all the values of nodes at level X is maximal.

Example 1:

Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
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
    int maxLevelSum(TreeNode* root) 
    {
        if(!root)
            return 0;
        int maxLevel=1,maxSum=INT_MIN,levelSum=0,level=1;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            int nodeCount=q.size();
            levelSum=0;
            while(nodeCount>0)
            {
                nodeCount--;
                TreeNode *temp=q.front();
                q.pop();
                if(temp)
                    levelSum+=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(levelSum>maxSum)
            {
                maxSum=levelSum;
                maxLevel=level;
            }
            level++;
        }
        return maxLevel;
    }
};
