/*
 * Given a Binary Tree. Check whether the Binary tree is a full binary tree or not.

Example 1:

Input:
          1
       /    \
      2      3
    /   \
   4     5
Output: 1
Explanation: Every node except leaf node
has two children so it is a full tree.
Example 2:

Input:
          1
       /    \
      2      3
    /
   4
Output: 0
Explanation: Node 2 has only one child
so this is not a full tree.
 */



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isFullTree (struct Node* root);
int main()
{
	int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        cout<<isFullTree(root)<<endl;
    }
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Return True if the given Binary Tree is a Full Binary Tree. Else return False

bool isFullTree (struct Node* root)
{
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        root = q.front();
        q.pop();
        bool hasLeft = false, hasRight = false;
        if(root->left)
        {
            q.push(root->left);
            hasLeft = true;
        }
        if(root->right)
        {
            q.push(root->right);
            hasRight = true;
        }
        if(hasLeft != hasRight)
            return false;
    }
    return true;
}
