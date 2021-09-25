/*
 * Given a Binary Tree, find vertical sum of the nodes that are in same vertical line.
 * Print all sums through different vertical lines starting from left-most vertical line to right-most vertical line.

Example 1:

Input:
       1
    /   \
  2      3
 / \    / \
4   5  6   7
Output:
Explanation:
The tree has 5 vertical lines
Vertical-Line-1 has only one node
4 => vertical sum is 4
Vertical-Line-2: has only one node
2=> vertical sum is 2
Vertical-Line-3: has three nodes:
1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3
=> vertical sum is 3
Vertical-Line-5: has only one node 7
=> vertical sum is 7
 */



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
  public:
    vector <int> verticalSum(Node *root)
    {
        // add code here.
        map<int, int>m;
        queue<pair<Node *, int>>q;
        q.push({root, 0});
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            m[temp.second] = m[temp.second] + temp.first->data;
            if(temp.first->left)
                q.push({temp.first->left, temp.second-1});
            if(temp.first->right)
                q.push({temp.first->right, temp.second+1});
        }
        vector<int>res;
        for(auto it=m.begin();it!=m.end();it++)
            res.push_back(it->second);
        return res;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        vector <int> res = obj.verticalSum(root);
        for (int i : res) cout << i << " ";
        cout<<endl;
    }
}  // } Driver Code Ends
