/*
 * Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges,
 * Find the number of strongly connected components in the graph.


Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
Example 2:

Input:

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.
 */



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution

{

public:

//Function to find number of strongly connected components in the graph.

//DFS function:
void dfs(int currentNode, vector<int> adj[],
		 vector<bool> &visited, stack<int> &s, bool isTopo)
{
       visited[currentNode] = true;

       for(auto next: adj[currentNode])
           if(!visited[next])
               dfs(next, adj, visited, s, isTopo);

       if(isTopo)
           s.push(currentNode);
}

int kosaraju(int V, vector<int> adj[])
{
       vector<int> transpose[V];
       for(int i=0; i<V; i++)
           for(auto j: adj[i])
               transpose[j].push_back(i);

       stack<int> s;
       vector<bool> visited(V, false);

       for(int i=0; i<V; i++)
           if(!visited[i])
               dfs(i, adj, visited, s, true);

       int count = 0;
       visited.assign(V, false);

       while(!s.empty())
       {
           int top = s.top();
           s.pop();
           if(visited[top])
               continue;
           dfs(top, transpose, visited, s, false);
           count++;
       }

       return count;
   }
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
