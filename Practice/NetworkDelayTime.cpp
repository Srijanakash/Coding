/*
There are N network nodes, labelled 1 to N.
Given times, a list of travel times as directed edges times[i] = (u, v, w), 
where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.
Now, we send a signal from a certain node K. 
How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
*/

# define INF 1000000
typedef pair<int, int> iPair; 
class Solution 
{ 
    int shortestPath(vector<pair<int,int> > adj[], int V, int src) 
    { // Dijkstra's Algorithm
        priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
        vector<int> dist(V, INF); 
        pq.push(make_pair(0, src)); 
        dist[src] = 0; 
        while (!pq.empty()) 
        { 
            int u = pq.top().second; 
            pq.pop(); 
            for (auto x : adj[u]) 
            { 
                int v = x.first; 
                int weight = x.second; 
                if (dist[v] > dist[u] + weight) 
                { 
                    dist[v] = dist[u] + weight; 
                    pq.push(make_pair(dist[v], v)); 
                } 
            } 
        } 
        int maxVal=INT_MIN;
        for(int i=0;i<dist.size();i++)
            maxVal=max(maxVal,dist[i]);
        return maxVal==INF?-1:maxVal;
    } 
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) 
    {
        vector<iPair>*adj=new vector<iPair>[N];
        for(int i=0;i<times.size();i++)
            adj[times[i][0]-1].push_back(make_pair(times[i][1]-1, times[i][2])); 
        return shortestPath(adj,N,K-1);
    }
};
