/*
 * Given a weighted, undirected and connected graph of V vertices and E edges,
 * Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.

Example 1:

Input:

S = 0
Output:
0 9
Explanation:
The source vertex is 0. Hence, the shortest distance
of node 0 is 0 and the shortest distance from node 9
is 9 - 0 = 9.
Example 2:

Input:

S = 2
Output:
4 3 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The other distances are pretty straight-forward.
 */



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> graph[], int src)
    {
        // Code here
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, src});
        vector<int>ans(V, 0);
        vector<bool>vis(V, false);
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int x = p.second;
            int wt = p.first;
            if(vis[x])
                continue;
            vis[x] = true;
            ans[x] = wt;
            for(auto y: graph[x])
                if(!vis[y[0]])
                    pq.push({wt + y[1], y[0]});
        }
        return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;

        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);

    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
