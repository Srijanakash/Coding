/*
Given a binary search tree with non-negative values, 
find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
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
    int res=INT_MAX,pre=-1;
public:
    int getMinimumDifference(TreeNode* root) 
    {
        if(!root)
            return 0;
        if(root->left)
            res=getMinimumDifference(root->left);
        if(pre>=0)
            res=min(res,abs(pre-root->val));
        pre=root->val;
        if(root->right)
            res=getMinimumDifference(root->right);
        return res;
    }
};
