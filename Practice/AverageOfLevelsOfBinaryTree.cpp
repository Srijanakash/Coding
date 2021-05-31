/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double>result;
        if(!root)
            return result;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            double maxValue=0.0;
            int nodeCount=q.size();
            for(int i=1;i<=nodeCount;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                maxValue+=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            result.push_back(maxValue/nodeCount);
        }
        return result;
    }
};
