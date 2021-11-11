/*
 * Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.


Example 1:


Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers
since per each level it does not matter the order on which elements are returned.
Example 2:

Input: root = [1]
Output: [[1]]
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
    unordered_map<int, vector<int>> umap;
    int dfs(TreeNode *root, int &height)
    {
        if(!root)
            return -1;
        int leftHeight = dfs(root->left, height);
        int rightHeight = dfs(root->right, height);
        height = max(leftHeight, rightHeight) + 1;
        umap[height].push_back(root->val);
        return height;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root)
    {
        int height = 0;
        dfs(root, height);
        vector<vector<int>> res;
        for(int i=0;i<=height;i++)
            res.push_back(umap[i]);
        return res;
    }
};
