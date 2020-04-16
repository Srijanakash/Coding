/*
In this problem, a tree is an undirected graph that is connected and has no cycles.
The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), 
with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.
The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, 
that represents an undirected edge connecting nodes u and v.
Return an edge that can be removed so that the resulting graph is a tree of N nodes. 
If there are multiple answers, return the answer that occurs last in the given 2D-array. 
The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
*/

class UnionFind 
{
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) : rank(n+1, 1), parent(n+1) 
    {
        for (int i = 0; i <= n; ++i) 
            parent[i] = i;
    }
    int find(int node) 
    {
        if (parent[node] != node) 
            parent[node] = find(parent[node]);
        return parent[node];
    }
    
    void Union(int n1, int n2) 
    {
        int root1 = find(n1);
        int root2 = find(n2);
        if (rank[root1] > rank[root2]) 
            parent[root2] = root1;
        else if (rank[root2] > rank[root1]) 
            parent[root1] = root2;
        else 
        {
            parent[root2] = root1;
            ++rank[root1];
        }
    }
};

class Solution 
{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = 0;
        for (int e = 0; e < edges.size(); ++e) 
            n = max(edges[e][0],max(edges[e][1],n));
        UnionFind uf(n);
        for (int e = 0; e < edges.size(); ++e) 
        {
            if (uf.find(edges[e][0]) == uf.find(edges[e][1]))
                return edges[e];
            uf.Union(edges[e][0], edges[e][1]);
        }
        return vector<int>{-1, -1};
    }
};
