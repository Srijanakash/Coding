/*
 * Given the root of a binary tree, return the vertical order traversal of its nodes' values.
 * (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Example 2:


Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]
Example 3:


Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
Output: [[4],[9,5],[3,0,1],[8,2],[7]]
Example 4:

Input: root = []
Output: []
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
public:
    vector<vector<int>> verticalOrder(TreeNode* root)
    {
        vector<vector<int>>res;
        if(!root)
            return res;
        map<int, vector<int>>m;
        queue<pair<TreeNode *, int>>q;
        q.push({root, 0});
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            vector<int> temp;
            if(m.find(node.second) != m.end())
                temp = m[node.second];
            temp.push_back(node.first->val);
            m[node.second] = temp;
            if(node.first->left)
                q.push({node.first->left, node.second - 1});
            if(node.first->right)
                q.push({node.first->right, node.second + 1});
        }

        for(auto it = m.begin(); it != m.end(); it++)
        {
            vector<int> temp = it->second;
            res.push_back(temp);
        }
        return res;
    }
};
