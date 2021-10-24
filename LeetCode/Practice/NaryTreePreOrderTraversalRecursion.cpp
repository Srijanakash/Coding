/*
 * Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal.
Each group of children is separated by the null value (See examples)



Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 */




/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    void preOrderHelper(Node *root, vector<int> &res)
    {
        if(!root)
            return;
        res.push_back(root->val);
        for(int i=0;i<root->children.size();i++)
            preOrderHelper(root->children[i], res);
    }
public:
    vector<int> preorder(Node* root)
    {
        vector<int>res;
        preOrderHelper(root, res);
        return res;
    }
};
