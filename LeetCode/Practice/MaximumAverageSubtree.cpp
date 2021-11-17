/*
Given the root of a binary tree, return the maximum average value of a subtree of that tree. 
Answers within 10-5 of the actual answer will be accepted.

A subtree of a tree is any node of that tree plus all its descendants.

The average value of a tree is the sum of its values, divided by the number of nodes.

 

Example 1:


Input: root = [5,6,1]
Output: 6.00000
Explanation: 
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have an average of 6 / 1 = 6.
For the node with value = 1 we have an average of 1 / 1 = 1.
So the answer is 6 which is the maximum.
Example 2:

Input: root = [0,null,1]
Output: 1.00000
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
    struct State
    {
        int nodeCount;
        int valueSum;
        double maxAverage;
    };
    State maxAverage(TreeNode *root)
    {
        if(!root)
            return {0, 0, 0};
        State left = maxAverage(root->left);
        State right = maxAverage(root->right);
        int nodeCount = left.nodeCount + right.nodeCount + 1;
        int sum = left.valueSum + right.valueSum + root->val;
        double maxAverage = max((1.0 * sum) / nodeCount, max(right.maxAverage, left.maxAverage));
        return {nodeCount, sum, maxAverage};
    }
public:
    double maximumAverageSubtree(TreeNode* root) 
    {
        return maxAverage(root).maxAverage;
    }
};