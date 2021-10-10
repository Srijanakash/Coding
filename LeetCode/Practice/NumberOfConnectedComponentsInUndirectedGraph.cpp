/*
 * You have a graph of n nodes. You are given an integer n
 * and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.



Example 1:


Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1

 */



class Solution
{
    void DFSUtil(int v, vector<bool> &vis, vector<int> adj[])
    {
        vis[v] = true;
        for(auto it = adj[v].begin(); it != adj[v].end(); it++)
            if(!vis[*it])
                DFSUtil(*it, vis, adj);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        vector<bool> vis(n ,false);
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int connectedComponents = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                DFSUtil(i, vis, adj);
                connectedComponents ++;
            }
        }
        return connectedComponents;
    }
};
