/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    bool isLeaf(TreeNode *root)
    {
        if(root==NULL)
            return false;
        if(root->left==NULL && root->right==NULL)
            return true;
        return false;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int sum=0;
        if(root!=NULL)
        {
            if(root->left!=NULL && isLeaf(root->left))
                sum+=root->left->val;
            sum+=sumOfLeftLeaves(root->left);
            sum+=sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};
