/*
 * Given a Directed Graph. Count the total number of ways or paths that exist between two vertices in the directed graph.
 * These paths doesn’t contain any cycle.
Note: Graph doesn't contain multiple edges,
self loop and cycles and the two vertices( source and destination) are denoted in the example.


Example 1:

Input:

Output: 4
Explanation:
There are 4 paths from 0 to 4.
0 -> 4
0 -> 1 -> 4
0 -> 2 -> 4
0 -> 1 -> 3 -> 2 -> 4

Example 2:

Input:

Output: 3
Explanation:
There are 3 paths from 0 to 3.
0 -> 3
0 -> 1 -> 3
0 -> 1 -> 2 -> 3
 */



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    int isVisited(int x, vector<int>& path)
    {
        int size = path.size();
        for (int i = 0; i < size; i++)
            if (path[i] == x)
                return 1;
        return 0;
    }
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination)
    {
        // Code here
        queue<vector<int>>q;
        vector<int>path;
        path.push_back(source);
        q.push(path);
        int numberPaths = 0;
        while(!q.empty())
        {
            path = q.front();
            q.pop();
            int last = path[path.size() - 1];
            if(last == destination)
                numberPaths++;
            for(int i=0;i<adj[last].size();i++)
            {
                if(!isVisited(adj[last][i], path))
                {
                    vector<int>newPath(path);
                    newPath.push_back(adj[last][i]);
                    q.push(newPath);
                }
            }
        }
        return numberPaths;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends
