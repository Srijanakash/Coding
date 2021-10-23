/*
 * There are n cities labeled from 1 to n.
 * You are given the integer n and an array connections where connections[i] = [xi, yi, costi]
 * indicates that the cost of connecting city xi and city yi (bidirectional connection) is costi.

Return the minimum cost to connect
all the n cities such that there is at least one path between each pair of cities.
If it is impossible to connect all the n cities, return -1,

The cost is the sum of the connections' costs used.



Example 1:


Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.
Example 2:


Input: n = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: There is no way to connect all cities even if all edges are used.
 */





class Solution
{
    struct DisjointSets
    {
        int *parent, *rank;
        int n;
        DisjointSets(int n)
        {
            this->n = n;
            parent = new int[n+1];
            rank = new int[n+1];
            for(int i=0; i<=n;i++)
            {
                rank[i] = 0;
                parent[i] = i;
            }
        }
        int find(int u)
        {
            if(u != parent[u])
                parent[u] = find(parent[u]);
            return parent[u];
        }
        bool merge(int u, int v)
        {
            u = find(u), v = find(v);
            if(u != v)
            {
                if(rank[u] > rank[v])
                    parent[v] = u;
                else
                    parent[u] = v;
                if(rank[u] == rank[v])
                    rank[v] ++;
                return true;
            }
            return false;
        }
    };

    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        return a[2] < b[2];
    }
public:
    int minimumCost(int n, vector<vector<int>>& connections)
    {
        DisjointSets ds(n);
        sort(connections.begin(), connections.end(), comp);
        int mstWt = 0, edges = 0;
        for(int i=0; i<connections.size();i++)
        {
            int u = connections[i][0], v = connections[i][1];
            if(ds.merge(u, v))
            {
                mstWt += connections[i][2];
                edges++;
            }
        }
        return edges == n-1 ? mstWt : -1;
    }
};
