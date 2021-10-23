/*
 * Given the root of a binary search tree, a target value, and an integer k,
 * return the k values in the BST that are closest to the target. You may return the answer in any order.

You are guaranteed to have only one unique set of k values in the BST that are closest to the target.



Example 1:


Input: root = [4,2,5,1,3], target = 3.714286, k = 2
Output: [4,3]
Example 2:

Input: root = [1], target = 0.000000, k = 1
Output: [1]
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
    priority_queue<pair<double, int>>pq;
    void findClosestValues(TreeNode *root, double target, int k)
    {
        if(!root)
            return;
        double diff = abs(root->val - target);
        pq.push({diff, root->val});
        if(pq.size() > k)
            pq.pop();
        findClosestValues(root->left, target, k);
        findClosestValues(root->right, target, k);
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k)
    {
        vector<int>res;
        findClosestValues(root, target, k);
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
