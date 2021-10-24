/*
 * Consider all the leaves of a binary tree, from left to right order,
 * the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.



Example 1:


Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
Example 2:

Input: root1 = [1], root2 = [1]
Output: true
Example 3:

Input: root1 = [1], root2 = [2]
Output: false
Example 4:

Input: root1 = [1,2], root2 = [2,2]
Output: true
Example 5:


Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
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
    vector<int> dfs(TreeNode *root)
    {
        vector<int>leaves;
        if(!root)
            return leaves;
        stack<TreeNode *>s;
        s.push(root);
        while(!s.empty())
        {
            root = s.top();
            s.pop();
            if(!root->left && !root->right)
                leaves.push_back(root->val);
            if(root->left)
                s.push(root->left);
            if(root->right)
                s.push(root->right);
        }
        return leaves;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> leaves1, leaves2;
        leaves1 = dfs(root1);
        leaves2 = dfs(root2);
        if(leaves1.size() != leaves2.size())
            return false;
        for(int i=0;i<leaves1.size();i++)
            if(leaves1[i] != leaves2[i])
                return false;
        return true;
    }
};
