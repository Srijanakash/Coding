/*
Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. 
The root node is at depth 1.

The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, 
create two tree nodes with value v as N's left subtree root and right subtree root. 
And N's original left subtree should be the left subtree of the new left subtree root, 
its original right subtree should be the right subtree of the new right subtree root. 
If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, 
and the original tree is the new root's left subtree.


Input: 
A binary tree as following:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

Output: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   

Input: 
A binary tree as following:
      4
     /   
    2    
   / \   
  3   1    

v = 1

d = 3

Output: 
      4
     /   
    2
   / \    
  1   1
 /     \  
3       1

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) 
    {
        if(!root)
            return NULL;
        if(d==1)
        {
            TreeNode *temp=new TreeNode(v);
            temp->left=root;
            root=temp;
            return root;
        }
        queue<TreeNode *>q;
        q.push(root);
        for(int i=1;i<d-1;i++)
        {
            int nodeCount=q.size();
            while(nodeCount>0)
            {
                nodeCount--;
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            TreeNode *temp1=new TreeNode(v);
            TreeNode *temp2=new TreeNode(v);
            TreeNode *left=temp->left,*right=temp->right;
            temp->left=temp1;
            temp->right=temp2;
            temp1->left=left;
            temp2->right=right;
        }
        return root;
    }
};
