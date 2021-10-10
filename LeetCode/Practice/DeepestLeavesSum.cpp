/*
 * Given the root of a binary tree, return the sum of values of its deepest leaves.


Example 1:


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
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
    bool checkLeaf(TreeNode *root)
    {
        if(!root->left && !root->right)
            return true;
        return false;
    }
public:
    int deepestLeavesSum(TreeNode* root)
    {
        int leavesSum = 0;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            int tempSum = 0;
            for(int i=0;i<size;i++)
            {
                root = q.front();
                q.pop();
                if(checkLeaf(root))
                    tempSum += root->val;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            if(tempSum > 0)
                leavesSum = tempSum;
        }
        return leavesSum;
    }
};
