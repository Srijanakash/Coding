/*
 * Given the root of a binary tree, return the lowest common ancestor (LCA) of two given nodes, p and q.
 * If either node p or q does not exist in the tree, return null. All values of the nodes in the tree are unique.

According to the definition of LCA on Wikipedia:
"The lowest common ancestor of two nodes p and q in a binary tree T
 is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)".
 A descendant of a node x is a node y that is on the path from node x to some leaf node.



Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:



Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5. A node can be a descendant of itself according to the definition of LCA.
Example 3:



Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 10
Output: null
Explanation: Node 10 does not exist in the tree, so return null.
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
    TreeNode *findLCAUtil(TreeNode *root, TreeNode *p, TreeNode *q, bool &flag1, bool &flag2)
    {
        if(!root)
            return NULL;
        if(root->val == p->val)
        {
            flag1 = true;
            return root;
        }
        if(root->val == q->val)
        {
            flag2 = true;
            return root;
        }
        TreeNode *leftNode = findLCAUtil(root->left, p, q, flag1, flag2);
        TreeNode *rightNode = findLCAUtil(root->right, p, q, flag1, flag2);

        if(leftNode && rightNode)
            return root;
        return leftNode? leftNode: rightNode;
    }
    bool findLca(TreeNode *root, TreeNode *node)
    {
        if(!root)
            return false;
        return root->val == node->val || findLca(root->left, node) || findLca(root->right, node);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        bool flag1 = false, flag2 = false;
        TreeNode *ans = findLCAUtil(root, p, q, flag1, flag2);
        if(flag1 && flag2 || flag1 && findLca(ans, q) || flag2 && findLca(ans, p))
            return ans;
        return NULL;
    }
};
