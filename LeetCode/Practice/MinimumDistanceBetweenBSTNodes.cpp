/*
 * Given the root of a Binary Search Tree (BST),
 * return the minimum difference between the values of any two different nodes in the tree.



Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
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
    void inorder(TreeNode *root, vector<int> &nodes)
    {
        if(!root)
            return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
public:
    int minDiffInBST(TreeNode* root)
    {
        vector<int>nodes;
        inorder(root, nodes);
        int minDistance = INT_MAX;
        for(int i=1;i<nodes.size();i++)
            minDistance = min(minDistance, nodes[i] - nodes[i-1]);
        return minDistance;
    }
};
