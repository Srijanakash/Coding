/*
Given two binary trees and imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not.
You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, 
then sum node values up as the new value of the merged node. 
Otherwise, the NOT null node will be used as the node of new tree.

Example 1:

Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
 

Note: The merging process must start from the root nodes of both trees.
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        if(!t1 && !t2) 
            return nullptr;
        if(!t1 || !t2) 
            return t1? t1:t2;
        queue<pair<TreeNode*,TreeNode *>> q1;
        q1.push({t1,t2});
        while(!q1.empty())
        {
            TreeNode* c1=(q1.front().first);
            TreeNode* c2=(q1.front().second);
            q1.pop();
            c1->val+=c2->val;
            if(!c1->left && c2->left) 
                c1->left = c2->left;
            else if(c1->left && c2->left) 
                q1.push({c1->left,c2->left});           
            if(!c1->right && c2->right) 
                c1->right = c2->right;
            else if(c1->right && c2->right) 
                q1.push({c1->right,c2->right}); 
        }
        return t1;
    }
};


/*
Soln2:

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        if(!t1) 
            return t2;
        if(!t2) 
            return t1;
        t1->val+=t2->val;
        if(t2->left) 
            t1->left = mergeTrees(t1->left,t2->left);
        if(t2->right) 
            t1->right = mergeTrees(t1->right,t2->right);
        return t1;
    }
};
*/
