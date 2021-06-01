/*
There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] 
represents a connection between computers a and b. 
Any computer can reach any other computer directly or indirectly through the network.
Given an initial computer network connections. You can extract certain cables between two directly connected computers, 
and place them between any pair of disconnected computers to make them directly connected. 
Return the minimum number of times you need to do this in order to make all the computers connected. 
If it's not possible, return -1. 

Example 1:

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
Example 4:

Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
Output: 0
*/

class Solution 
{
    void dfs(vector<bool>&vis,vector<int>graph[],int index)
    {
        vis[index]=true;
        stack<int>s;
        s.push(index);
        while(!s.empty())
        {
            index=s.top();
            s.pop();
            for(int i=0;i!=graph[index].size();i++)
            {
                if(!vis[graph[index][i]])
                {
                    s.push(graph[index][i]);
                    vis[graph[index][i]]=true;
                }
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if(n-1>(connections.size()))
            return -1;
        int ans=-1;
        vector<bool>vis;
        vis.assign(n,false);
        vector<int>graph[n];
        for(int i=0;i<connections.size();i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(vis,graph,i);
                ans++;
            }
        }
        return ans;
    }
};
