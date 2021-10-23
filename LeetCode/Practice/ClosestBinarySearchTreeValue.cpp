/*
 * Given the root of a binary search tree and a target value,
 * return the value in the BST that is closest to the target.



Example 1:


Input: root = [4,2,5,1,3], target = 3.714286
Output: 4
Example 2:

Input: root = [1], target = 4.428571
Output: 1
 */




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    int findClosest(TreeNode *root, double diff, int nodeVal, double target)
    {
        if(!root)
            return nodeVal;
        if(abs(root->val-target) < diff)
        {
            diff = abs(root->val - target);
            nodeVal = root->val;
        }
        if(diff == 0)
            return nodeVal;
        if(root->val > target)
            return findClosest(root->left, diff, nodeVal, target);
        return findClosest(root->right, diff, nodeVal, target);
    }
public:
    int closestValue(TreeNode* root, double target)
    {
        return findClosest(root, INT_MAX, 0, target);
    }
};
