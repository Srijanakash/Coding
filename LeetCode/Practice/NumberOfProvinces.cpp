/*
 * There are n cities. Some of them are connected, while some are not.
 * If city a is connected directly with city b, and city b is connected directly with city c,
 * then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1
if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.



Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 */



class Solution
{
    void DFSUtil(int v, vector<bool> &vis, vector<int>adj[])
    {
        vis[v] = true;
        for(auto it = adj[v].begin(); it != adj[v].end(); it ++)
            if(!vis[*it])
                DFSUtil(*it, vis, adj);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int V = isConnected.size();
        vector<int> adj[V];
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(isConnected[i][j])
                    adj[i].push_back(j);

        int numberOfProvinces = 0;
        vector<bool> vis(V, false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                DFSUtil(i, vis, adj);
                numberOfProvinces ++;
            }
        }
        return numberOfProvinces;
    }
};
