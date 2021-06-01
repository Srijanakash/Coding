/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
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
    bool checkMirror(TreeNode *a,TreeNode *b)
    {
        if(!a && !b)
            return true;
        if(!a || !b)
            return false;
        return (a->val==b->val && checkMirror(a->left,b->right) && checkMirror(a->right,b->left));
    }
public:
    bool isSymmetric(TreeNode* root) 
    {
        return checkMirror(root,root);
    }
};
