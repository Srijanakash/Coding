/*
 * Given a Directed Graph, find a Mother Vertex in the Graph (if present).
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.


Example 1:

Input:

Output: 0
Explanation: According to the given edges, all
nodes can be reaced from nodes from 0, 1 and 2.
But, since 0 is minimum among 0,1 and 3, so 0
is the output.
Example 2:

Input:

Output: -1
Explanation: According to the given edges,
no vertices are there from where we can
reach all vertices. So, output is -1.
 */




// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    void DFSUtil(int v, vector<bool> &vis, vector<int> adj[])
    {
        vis[v] = true;
        for(auto i=adj[v].begin(); i!=adj[v].end(); i++)
            if(!vis[*i])
                DFSUtil(*i, vis, adj);
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> vis(V, false);
	    int v = 0;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            DFSUtil(i, vis, adj);
	            v = i;
	        }
	    }
	    fill(vis.begin(), vis.end(), false);
	    DFSUtil(v, vis, adj);
	    for(int i=0;i<V;i++)
	        if(!vis[i])
	            return -1;
	    return v;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
