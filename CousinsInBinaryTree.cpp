/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:
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
    bool isCousins(TreeNode* root, int x, int y) 
    {
         if(root->left==NULL && root->right==NULL)
            return true;
        else
        {
            queue<TreeNode*> q;
            q.push(root);
            queue<TreeNode*> par;
            int c=0;
            int c1=0;
            while(q.size()!=NULL)
            {
                int nodes=q.size();
                while(nodes>0)
                {
                    TreeNode* curr=q.front();
                    q.pop();
                    if(curr->val==x || curr->val==y)
                        c1++;
                    if(curr->left!=NULL)
                    {
                      q.push(curr->left);
                      if(curr->left->val==x || curr->left->val==y)
                          c++;
                    }
                    if(curr->right!=NULL)
                    {
                        q.push(curr->right);
                        if(curr->right->val==y || curr->right->val==x)
                            c++;
                    }
                    if(c==2)
                    {
                        return false;
                        break;
                    }
                    if(c1==2 && c!=2)
                    {
                        return true;
                        break;
                    }
                    
                    nodes--;
                    c=0;
                }
                c1=0;
                c=0;
            }
            
            return false;
            
        }
    }
};
