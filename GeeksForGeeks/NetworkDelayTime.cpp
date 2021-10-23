/*
 * You are given a network of n nodes, labeled from 1 to n.
 * You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi),
 * where ui is the source node, vi is the target node,
 * and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k.
Return the time it takes for all the n nodes to receive the signal.
If it is impossible for all the n nodes to receive the signal, return -1.



Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 */




class Solution
{
    int shortestPath(vector<pair<int, int>> adj[], int n, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist (n, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for(auto x: adj[u])
            {
                int v = x.first;
                int w = x.second;
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxVal = INT_MIN;
        for(int i=0;i<n;i++)
            maxVal = max(maxVal, dist[i]);
        return maxVal==INT_MAX?-1:maxVal;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<pair<int, int>>*adj=new vector<pair<int, int>>[n];
        for(int i=0;i<times.size();i++)
            adj[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
        return shortestPath(adj, n, k-1);
    }
};
