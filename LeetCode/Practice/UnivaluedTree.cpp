/*
A binary tree is univalued if every node in the tree has the same value.
Return true if and only if the given tree is univalued.

Example 1:

Input: [1,1,1,1,1,null,1]
Output: true
Example 2:

Input: [2,2,2,5,2]
Output: false
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
    bool isUnivalTree(TreeNode* root) 
    {
        static int val=INT_MIN;
        if(!root)
            return true;
        if(root->left)
        {
            if(root->left->val!=root->val)
                return false;
        }
        if(root->right)
        {
            if(root->right->val!=root->val)
                return false;
        }
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
